#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 
int num;
void getGray(int n,char **Gray){
	if(n==1){// 边界条件 
		return;
	}
	getGray(n-1,Gray);
	int m = 1<<(n-1);//Gray(n-1)的数量，即Gray(n)一半的位置 
	for(int i=m;i>0;i--){
		strcpy(Gray[++m], Gray[i]);
		Gray[m][num-n] = '1';
//		Gray[m][strlen(Gray[0])-n] = '1'; 为什么这个不行 
	}
	return;
}


int main(){
	int n;
	printf("n=");scanf("%d",&n);
	num = n;//记录 
	char **Gray = (char**)malloc(sizeof(char*)*((1<<n)+1));//首位不用
	for(int i=1;i<(1<<n)+1;i++){
		Gray[i]=(char*)malloc(sizeof(char)*(n+1));//最后一位放'\n'
	}//添加字符串结束标志，便于输出
	//初始化0,1 
	for(int i=0;i<n-1;i++){
			Gray[1][i]='0';
			Gray[2][i]='0';
		}
	Gray[1][n-1]='0'; 
	Gray[2][n-1]='1'; 
	Gray[1][n]='\0'; 
	Gray[2][n]='\0';

	getGray(n,Gray);
	for(int i=1;i<(1<<n)+1;i++){
		printf("%s\n",Gray[i]);
	}
 
return 0;
}

