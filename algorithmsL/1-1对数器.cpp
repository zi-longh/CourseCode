#include<stdio.h>
#include<stdlib.h> // standard_library
#include<math.h>
int main(){
	int n ;
	for(int k=100;k<9999;k++){
	n = k; 
	
	//������ 
	int arr2[10]={0};
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
			arr2[ num[j] ]++;
		}
	}		

	int i,j,highter,lower,temp;
	int ws;
	//�������ҳ�ʼ������
	int count[10]={0};
	//����n��λ��
	ws=log10((double)n)+1;
 
	//���μ����i��iС��ws��λ0��9���ֵĴ���
	for(i=1;i<=ws;i++){
 
		//��¼��iλ֮�ϵĸ�λ
		highter=n/(int)pow((double)10,i);
		
		//��¼��iλ֮�µĵ�λ
		lower=n%(int)pow((double)10,i-1);
 
		//��¼��iλ
		temp=(n/(int)pow((double)10,i-1))%10;
 
		//��¼С�ڵ�iλ��������iλ���ֵĴ���
		for(j=0;j<temp;j++){
			count[j]+=(highter+1)*pow((double)10,i-1);
		}
 
		//��¼��iλ�ϵ������ڵ�iλ���ֵĴ���
		count[temp]+=highter*pow((double)10,i-1)+lower+1;
		
		//��¼���ڵ�iλ�������ڵ�iλ���ֵĴ���
		for(j=temp+1;j<10;j++){
			count[j]+=highter*pow((double)10,i-1);
		}
	}
 
	//�޳������0
	for(i=0;i<ws;i++)  
        count[0]-=(int)pow((double)10,i);
		
	int flag = 0;
	for(int i=0;i<10;i++){
		if(count[i] != arr2[i]){
			printf("error: n = %d",n);
			flag = 1;
			break;
		}
	}
	if(flag){
		break; 
	}
			
	} 
return 0;
}

