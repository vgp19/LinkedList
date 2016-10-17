#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

struct Node* add(struct Node *n,int *value);
struct Node* search(struct Node *n,int *value);
int isEmpty(struct Node *n);
struct Node* delete(struct Node *n, struct Node *head);
void printList(struct Node *n);

int main(int argc, char* argv[]){
	
	FILE *file;
	int num=0;
	int c=0;
	int j=2;
	int len=0;
	char str[255];
	struct Node *tmp;
	tmp=NULL;
	struct Node *headPtr;
	headPtr=NULL;
	if(argc<2){
		printf("error\n");
		return 0;
	}
	file=fopen(argv[1],"r");
	if(file==NULL){
		printf("error\n");
		return 0;
	}
	while(fgets(str,255,file)!=NULL){
		int i=0;
		num=0;
		j=2;
		c=0;
		len=strlen(str);
		len=str[len-1]=='\n'?len-1:strlen(str);
			if((str[0]!='d' && str[0]!='i') || str[1]!='\t'){
				printf("error\n");
				return 0;
			}else{
				if(str[2]-'0'==-3)
					c=1;
				for(i= c==1?3:2;i<len;i++){
					if(!((str[i]-'0'>=0&&str[i]-'0'<=9))){
						printf("error\n");
						return 0;
					}	
				}
					if(c==1)
						j=3;
					while(j<len){
						num=num*10+(str[j]-'0');
						j++;
					}
					if(c==1)
						num=num*(-1);
					tmp=search(headPtr,&num);
					if(str[0]=='i'){
						if(tmp==NULL){
							headPtr=add(headPtr,&num);
						}
					}else{
						if(tmp!=NULL)
							headPtr=delete(tmp,headPtr);
					}
				
			}
	}
	printList(headPtr);
	fclose(file);
	free(headPtr);
	return 0;
}

struct Node* search(struct Node *n, int *value){
	struct Node *prev;
	struct Node *tmp;
	if(isEmpty(n)==1){
		return NULL;
	}else{
		prev=n;
		tmp=n;
		while(tmp!=NULL){
			if(tmp->data==*value)
				return prev;
			prev=tmp;
			tmp=tmp->next;
		}
	return NULL;
}
}
struct Node* add(struct Node *n, int *value){
	struct Node *prev;
	struct Node *ahead;
	struct Node* tmpNode=(struct Node*)malloc(sizeof(struct Node));
	tmpNode->data=*value;
	tmpNode->next=NULL;
	if(isEmpty(n)==1){
		n=tmpNode;
		return n;
	}else{
		if(n->next==NULL){
			if(n->data<*value){
				n->next=tmpNode;
				return n;
			}
			else{
				tmpNode->next=n;
				return tmpNode;
			}
		}
		if(n->data>*value){
			tmpNode->next=n;
			return tmpNode;
		}
		ahead=n->next;
		prev=n;

		while(ahead!=NULL){
			if(ahead->data>*value&&prev->data<*value){
				prev->next=tmpNode;
				tmpNode->next=ahead;
				return n;
			}
			prev=ahead;
			ahead=ahead->next;
		}

		prev->next=tmpNode;
		return n;
	}
	}
struct Node* delete(struct Node *n, struct Node *head){
	struct Node *prev;
	prev=n;
	if(n==head){
		head=n->next;
	}else{
		prev->next=prev->next->next;
	}
	return head;
}
int isEmpty(struct Node *n){
	if(n==NULL)
		return 1;
	else 
		return 0;
}
void printList(struct Node *n){
	struct Node *tmp;
	tmp=n;
	if(isEmpty(n)==1){
		printf("\n");
	}
	else{
		while(tmp!=NULL){
			printf("%d\t",tmp->data);
			tmp=tmp->next;
		}
	}
	return;
}

