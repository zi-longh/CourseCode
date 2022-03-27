#include<stdio.h>
int main(){
	int arr[10]={0};//保存每一个数出现次数的计数器数组 
	int pow10[10]={1};//每一位的权值
	for(int i=1;i<10;i++)pow10[i]=10*pow10[i-1];
	int n ; scanf("%d",&n); //输入n 
	int num[3][10]={0};
	//[0]存每一位的值V
	//[1]存每一位前面一串数的值F
	//[2]存每一位后面一串数的值R 
	
	int len=0; //记录位数 P
	while(n/10){ // 拆分n的每一位，获取VFR 
		num[0][len] = n%10;
		num[2][len+1] += n%10*pow10[len] + num[2][len];
		n = n/10;
		num[1][len++]=n;
	}
	num[0][len++] = n;
	int i = 0; 
	for(i=0;i<len;i++){ //逐位计算 
		for(int j=0;j<10;j++){
			arr[j] += num[1][i]*pow10[i]; 
			if(j==num[0][i]){
				arr[j] += num[2][i] + 1;
			}
			else if(j<num[0][i]&&j!=0){
				arr[j] += pow10[i];
			}
		}
	}
	for(int i=0;i<10;i++)printf("%d\n",arr[i]); //输出结果 
return 0;
}

/*
对于输入数n，其任意位都有VFRP（对于最高位，取F=0；对于第一位，取R=0），考虑其任意一位，有如下四种规则：
①0-9各数在该为的出现次数至少为：F×10P-1
②对于0-9中大于V的数，出现次数不必额外增加。
③对于0-9中等于V的数，出现次数与还R有关，需加上：R + 1（0到x，共有x+1个数）
④对于1-9中小于V的数，需加上：10P-1   


*/ 


