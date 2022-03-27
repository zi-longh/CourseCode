#include<stdio.h>
#include<stdlib.h> // standard_library

int data[1001]; //假设每个数都小于1000 , 默认都为零 
int main(){
	int n; printf("n="); scanf("%d",&n);
	int *arr = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int *indexs = (int*)malloc(sizeof(int)*n); int len; 
	for(int i=0;i<n;i++){
		data[arr[i]]++;
	}
	int z,c=-1;
	for(int i=0;i<n;i++){
		if(data[arr[i]] > c){
			c = data[arr[i]];
			z = arr[i];
		}
	}
	printf("---------\n%d\n%d",z,c);
	
return 0;
}

