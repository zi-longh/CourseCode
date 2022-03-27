#include<stdio.h>
#include<stdlib.h> // standard_library
#include<math.h>
int main(){
	int n ;
	for(int k=100;k<9999;k++){
	n = k; 
	
	//暴力法 
	int arr2[10]={0};
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
			arr2[ num[j] ]++;
		}
	}		

	int i,j,highter,lower,temp;
	int ws;
	//声明并且初始化数组
	int count[10]={0};
	//计算n的位数
	ws=log10((double)n)+1;
 
	//依次计算第i（i小于ws）位0到9出现的次数
	for(i=1;i<=ws;i++){
 
		//记录第i位之上的高位
		highter=n/(int)pow((double)10,i);
		
		//记录第i位之下的低位
		lower=n%(int)pow((double)10,i-1);
 
		//记录第i位
		temp=(n/(int)pow((double)10,i-1))%10;
 
		//记录小于第i位的数字在i位出现的次数
		for(j=0;j<temp;j++){
			count[j]+=(highter+1)*pow((double)10,i-1);
		}
 
		//记录第i位上的数字在第i位出现的次数
		count[temp]+=highter*pow((double)10,i-1)+lower+1;
		
		//记录大于第i位的数字在第i位出现的次数
		for(j=temp+1;j<10;j++){
			count[j]+=highter*pow((double)10,i-1);
		}
	}
 
	//剔除多余的0
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

