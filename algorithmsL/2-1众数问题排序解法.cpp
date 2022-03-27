#include<stdio.h>
#include<stdlib.h> // standard_library
//快速排序 
int Quick_Sort(int *data,int data_lenth,int low,int high){
	if(low<high){
		int pkey = data[low],t;
		int low2 = low,high2 = high;
		while(low2<high2){
			while(low2<high2 && data[high2]>=pkey)high2--;  
			data[low2] = data[high2];
			while(low2<high2 && data[low2]<=pkey)low2++;
			data[high2] = data[low2];
		}
		data[low2] = pkey; 
		int ploc = low2;		
		Quick_Sort(data,data_lenth,low,ploc-1);
		Quick_Sort(data,data_lenth,ploc+1,high);		
	}
	return 1;	 
}

int main(){
	int n; printf("n="); scanf("%d",&n);
	int *arr = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	Quick_Sort(arr,n,0,n-1);
	int z=-1,c=-1;//众数，重数 
	int zt=-1,ct=-1;//临时众数和重数 ， 打擂台法 
	
	for(int i=1;i<n;i++){
		if(arr[i]!=zt){
			zt = arr[i];
			ct = 1;
		}else if(arr[i]==zt){
			ct++;
		}
		if(ct>c){
			c = ct;
			z = zt;
		}	
	}
	printf("---------\n%d\n%d\n",z,c);	
return 0;
}

/*

6
2
2
2
1
5
3


11
2
2
2
1
5
3
5
7
5
5
5

*/








