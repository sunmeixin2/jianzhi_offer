

/*
  面试题3（二）：不修改数组找出重复的数字
  题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
  少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
  数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
  输出是重复的数字2或者3。

*/


#include<stdio.h>
int getDuplication(const int* nums,int len){
	if(nums == NULL || len<=0){
		return -1;
	}
	int i;
	for(i=0;i<len;i++){
		if(nums[i]<=0 || nums[i]>=len){
			return -1;
		}
	}
	int start=1;
	int end=len-1;
	while(end>=start){
		int middle=(end+start)/2;
		//int middle=((end-start)>>1)+start;
		int count=countRange(nums,len,start,middle);
		if(end==start){
			if(count>1)
				return start;
			else
				break;
		}
		if(count > (middle-start+1)){
			end=middle;
		}
		else
			start=middle+1;
	}
	return -1;
}
int countRange(const int* nums,int len,int start,int end){
	int i;
	if(nums == NULL)
		return 0;
	int count=0;
	for(i=0;i<len;i++){
		if(nums[i]>=start && nums[i]<=end){
			count++;
		}
	}
	printf("count:%d\n",count);
	return count;
}
main(){
//	int nums[] = { 1, 2, 3, 4, 5, 6, 7, 4};
//	int nums[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
//	int nums[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
	int nums[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
//	int nums[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
//	int nums[] = { 1, 1 };
	//int nums[]={2,3,5,4,2,3,6,7};
	int value;
	value=getDuplication(nums,sizeof(nums)/sizeof(int));
	printf("value:%d",value);
}



