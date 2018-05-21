#include<stdio.h>
#include<stdlib.h>
void reOrderArray1(int *nums,int len){		//奇数和奇数，偶数和偶数之间的相对位置不变
	int i;
	int flag=1;
	int temp;
	while(flag){
		flag=0;
		for(i=0;i<len-1;i++){
			
			if(nums[i]%2==0 && nums[i+1]%2==1){
				temp=nums[i];
				nums[i]=nums[i+1];
				nums[i+1]=temp;
				flag=1;
			}
			
		}
		//flag=0;
	}
	for(i=0;i<len;i++){
		printf("%d ",nums[i]);
	}
	
}
void  reOrderArray(int *nums,int len){		//奇数和奇数，偶数和偶数之间的相对位置f发生改变
	int p1,p2;
	int temp;
	p1=0;
	p2=len-1;
	int i;
	while(p1<p2){
		while(p1<p2 && nums[p1]%2!=0)
			p1++;
		while(p1<p2 && nums[p2]%2!=1)
			p2--;
		if(p1<p2){
			temp=nums[p1];
			nums[p1]=nums[p2];
			nums[p2]=temp;
		}
			
	}
	for(i=0;i<len;i++){
		printf("%d ",nums[i]);
	}
} 
int main(){
	int nums[9]={1,2,3,4,5,6,7,8,9};
	int len=sizeof(nums)/sizeof(int);
//	printf("%d",len);
	reOrderArray(nums,len);
	return 0;
} 
