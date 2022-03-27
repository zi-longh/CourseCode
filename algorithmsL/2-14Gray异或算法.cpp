#include<stdio.h>
#include<stdlib.h> 
int main(){
	int n;printf("n=");scanf("%d",&n);
	int t = 0;
	char *gray = (char*)malloc(sizeof(char)*(n+1));//保存每次生成的格雷码
	gray[n] = '\0';//字符串结束标志，方便输出
    
    //异或生成格雷码
	for(int i=0;i<(1<<n);i++){
		t = (i>>1)^i;//G(n)=b(n) xor b(n+1)
        
        //将十进制表示的格雷码转换为二进制
		for(int i=1;i<n+1;i++){
			if(t&1) gray[n-i] = '1';
			else gray[n-i] = '0';
			t=t>>1;
		}
        //这里直接输出，也可以保存到相关数组内
		printf("%s\n",gray);
	}
return 0;
}
