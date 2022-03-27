#include<stdio.h>
#include<stdlib.h> // standard_library
#include<string.h>
int main(){
	int n; 
	printf("n=");
	scanf("%d",&n); 
	char **Gray = (char**)malloc(sizeof(char*)*((1<<n)+1));//首位不用
	for(int i=1;i<(1<<n)+1;i++){
		Gray[i]=(char*)malloc(sizeof(char)*(n+1));//最后一位放'\n'
	}
	//初始化0,1 
	for(int i=0;i<n-1;i++){
			Gray[1][i]='0';
			Gray[2][i]='0';
		}
	Gray[1][n-1]='0'; 
	Gray[2][n-1]='1'; 
	Gray[1][n]='\0'; 
	Gray[2][n]='\0';
	
	for(int i=2;i<n+1;i++){
		int m = 1<<(i-1);
		for(int j=1;j<m+1;j++){
			strcpy(Gray[m+j], Gray[m-j+1]);
			Gray[m+j][n-i] = '1';
		}
	}
	
	for(int i=1;i<(1<<n)+1;i++){
		printf("%s\n",Gray[i]);
	}
	
return 0;
}

