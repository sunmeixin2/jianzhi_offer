#include<stdio.h>
#include<stdlib.h>
void shell_sort(int *arr,int len){
	int i,j,gap;
	for(gap = len/2;gap > 0;gap/=2){		//设定步长 
		for(i=0;i<gap;i++){					//有多长步长就有多少循环 
			for(j=i+gap;j<len;j+=gap){		//此for循环是插入排序操作 
				if(arr[j]<arr[j-gap]){
					int temp =arr[j];
					int k=j-gap;
					while(k>=0 && arr[k]>temp){
						arr[k+gap]= arr[k];
						k=k-gap;
					}
					arr[k+gap]=temp;
				}
			}
		}
	}
	
}
int main(){
	
	int arr[] = {12,24,5,8,3,9,11,7};
	int len = sizeof(arr)/sizeof(int);
	int i;
	shell_sort(arr,len);
	for(i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	return 0;
} 
