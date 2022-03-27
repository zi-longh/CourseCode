#include<stdio.h>
#include<stdlib.h> 
#include<math.h>

void getGray(int n,int *Gray){
	if(n==1){
		Gray[1]=0;Gray[2]=1;
		return;
	}
	getGray(n-1,Gray);
	int m = 1<<(n-1);//Gray(n-1)的最后一个 
					//前半部分，直接用。 
	for(int i=m;i>0;i--){  
		Gray[++m] = (int)pow(10,n-1) + Gray[i]; //	后半部分：镜像排列，首位补1 
	}
	return;
}

int main(){
	int n;
	printf("n=");scanf("%d",&n);
	int *Gray = (int*)malloc(sizeof(int)*((1<<n)+1));//首位不用
	getGray(n,Gray);
	for(int i=1;i<(1<<n)+1;i++){
		printf("%0*d\n",n,Gray[i]);
	}
 
return 0;
}


