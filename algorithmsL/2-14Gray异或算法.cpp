#include<stdio.h>
#include<stdlib.h> 
int main(){
	int n;printf("n=");scanf("%d",&n);
	int t = 0;
	char *gray = (char*)malloc(sizeof(char)*(n+1));//����ÿ�����ɵĸ�����
	gray[n] = '\0';//�ַ���������־���������
    
    //������ɸ�����
	for(int i=0;i<(1<<n);i++){
		t = (i>>1)^i;//G(n)=b(n) xor b(n+1)
        
        //��ʮ���Ʊ�ʾ�ĸ�����ת��Ϊ������
		for(int i=1;i<n+1;i++){
			if(t&1) gray[n-i] = '1';
			else gray[n-i] = '0';
			t=t>>1;
		}
        //����ֱ�������Ҳ���Ա��浽���������
		printf("%s\n",gray);
	}
return 0;
}
