#include<stdio.h>
#include<stdlib.h> // standard_library

int main(){
	int arr[10]={0};//����ÿһ�������ֵĴ��� 
	int n ;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		//���һ����ÿһλ
		int num[10]={0};//��ÿһλ��ֵ 
		int len=0; //�������λ�� 
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

