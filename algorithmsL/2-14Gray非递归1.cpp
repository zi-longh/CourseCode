#include<stdio.h>
#include<stdlib.h> // standard_library
#include<math.h>
int main(){
	int n; 
	printf("n=");
	scanf("%d",&n); 
	int *Gray = (int*)malloc(sizeof(int)*((1<<n)+1));//首位不用
	Gray[1]=0;Gray[2]=1;//初始化0,1 

	for(int i=2;i<n+1;i++){
		int m = 1<<(i-1);
		for(int j=1;j<m+1;j++){
			Gray[m+j] = (int)pow(10,i-1) + Gray[m-j+1];
		}
	}
	
	for(int i=1;i<(1<<n)+1;i++){
		printf("%0*d\n",n,Gray[i]);
	}
	
return 0;
}
