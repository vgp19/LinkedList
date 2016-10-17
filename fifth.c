#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
FILE *file;
char str[255];
int m;
int n;
int i=0;
int j=0;
int strcount=0;
int len=0;
if(argc!=2){
printf("error\n");
return 0;
}
file=fopen(argv[1],"r");
	fgets(str,255,file);
	m=atoi(&str[0]);
	n=atoi(&str[2]);
	int matrix[m][n];
	int sum[m][n];
	while(i<m){
	j=0;
	strcount=0;	
	fgets(str,255,file);
		len=strlen(str);
		len=str[len-1]=='\n'?len-1:strlen(str);
		while(j<len){
			matrix[i][strcount]=atoi(&str[j]);
			j=j+2;
			strcount++;
		}
		i=i+1;	
	}
	fgets(str,255,file);
	i=0;
	while(fgets(str,255,file)!=NULL){
		j=0;
		strcount=0;
		len=strlen(str);
		len=str[len-1]=='\n'?len-1:strlen(str);
		while(j<len){
		
			sum[i][strcount]=(atoi(&str[j]))+matrix[i][strcount];
			j=j+2;
			strcount++;
		}
	i=i+1;
	}
	i=0;
	while(i<m){
	j=0;
		while(j<n){
			printf("%d\t",sum[i][j]);
			j++;
		}
			printf("\n");
		i++;
	}
	return 0;
	
	
}
