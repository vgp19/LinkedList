#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
	char* data;
	struct Node* next;
};
int getKey(int data);
void add(int key, char* data);
int search(int key,char* data);
struct Node* hashTable[1000];
int counter=0;

int getKey(int data){
	int key=0;
	key=data%1000;
	
	key=abs(key);
	return key;
}

int search(int key,char* data){
	if(hashTable[key]==NULL){
		return 0;
	}else{

		struct Node* tmp;
		tmp=hashTable[key];
		while(tmp!=NULL){

			if(strcmp(tmp->data,data)==0){
				return 1;
			}
			tmp=tmp->next;
		}
	}

	return 0;
}

void add(int key, char* data){
	if(hashTable[key]==NULL){

		struct Node* tmp;
		tmp=(struct Node*)malloc(sizeof(struct Node));
		tmp->data=data;
		tmp->next=NULL;
		hashTable[key]=tmp;
		counter++;

	}else{
		if(search(key,data)==0){

			struct Node* tmp;
			tmp=hashTable[key];
			while(tmp->next!=NULL){
				tmp=tmp->next;	
			}
			struct Node* tmpNode;
			tmpNode=(struct Node*)malloc(sizeof(struct Node));
			tmpNode->data=data;
			tmpNode->next=NULL;
			tmp->next=tmpNode;
			counter++;

		}
	}	


}

int main(int argc, char* argv[]){
	int number=0;
	int i=0;
	FILE* f;
	char str[255];
	int len=0;
	char substr[255];
	int key;
	char* data;
	for(i=0;i<1000;i++){
		hashTable[i]=NULL;
	}
	if(argc<2){

		return 0;
	}
	f=fopen(argv[1],"r");
	if(f==NULL){
		printf("error\n");
		return 0;
	}	
	if(fgets(str,255,f)==NULL){
		printf("0\n");
		fclose(f);
		return 0;
	}	
	do{
		data=(char*)malloc(sizeof(str));
		strcpy(data,str);
		memcpy(substr,&str[2],strlen(str));
		substr[strlen(str)]='\0';

		number = (int)strtol(substr, NULL, 16);

		key=getKey(number);
		add(key,data);
	}while(fgets(str,255,f)!=NULL);	
	
	
	printf("%d\n",counter);
	fclose(f);
	free(data);
	return 0;
}

