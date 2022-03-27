#include<stdio.h>
#include<stdlib.h> // standard_library

int main(){
	int arr[10]={0};//保存每一个数出现的次数 
	int n ;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		//拆分一个数每一位
		int num[10]={0};//存每一位的值 
		int len=0; //这个数的位数 
		int m = i;
		while(m/10){
			num[len++] = m%10;
			m = m/10;
		}
		num[len++] = m;
		
		for(int j=0;j<len;j++){
			arr[ num[j] ]++;
		}
	} 
	for(int i=0;i<10;i++){
	printf("%d\n",arr[i]);
	}
return 0;
}

