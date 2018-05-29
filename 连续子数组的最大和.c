/*
	题目：输入一个整型数组，数组里有正数也有负数，数组中的一个或连续多个整数组成一个子数组。
			求所有子数组的和的最大值。
*/

#include<stdio.h>
#include<string.h>
int MaxSumOfsubArray(int *nums,int len){
	if(nums==NULL || len <=0)
		return 0;
	int sum=0;
	int max=0x80000000;		
	for(int i=0;i<len;i++){
		if(sum<=0)
			sum=nums[i];
		else
			sum+=nums[i];
		if(sum>max)
			max=sum;
	}
	return max;
}	
int main(){
	int nums[]={1,-2,3,10,-4,7,2,-5};
	//int nums[]={-2,-8,-1,-5,-9};
	//int nums[]={2,8,1,5,9};
	int len=sizeof(nums)/sizeof(int);
	int result;
	result=MaxSumOfsubArray(nums,len);
	printf("result= %d\n",result);
	return 0;
}
