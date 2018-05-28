/*
	题目：数组中有一个数字出现的次数超过数组长度的一半
		例如：，输入一个长度为９的数组｛１，２，３，２，２，２，５，４，２｝。
				此数字是２，在数组中出现了５次，超过了数组长度的一半。
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool CheckMoreThanHalf(int *nums,int len,int result){

	int times=0;
	for(int i=0;i<len;i++){
		if(nums[i]==result)
			times++;
	}

	if(times*2<=len)
		return false;
	return true;

}
int MoreThanHalfNum(int *nums,int len){
	
	if(nums==NULL || len <= 0)
		return 0;

	int result=nums[0];
	int times=1;
	for(int i=1;i<len;i++){
		if(nums[i] == result){
			times++;
		}else{
			times--;
		}
		if(times == 0){
			result=nums[i];
			times=1;
		}
	}

	if(!CheckMoreThanHalf(nums,len,result))
		return 0;


	return result;
}
int main(){
	int nums[]={1,2,3,2,2,2,5,4,2};
	int len=sizeof(nums)/sizeof(int);
	int result;
	result=MoreThanHalfNum(nums,len);
	printf("%d\n",result);
	return 0;
}

/*
	题解：数组中一个数字出现的次数超过数组长度的一半，，也就是说他出现的次数比其他数字出现的次数的和还多。因此可以在遍历数组的时候，
		当遍历的数字和前一个保存的数字相同，则times加一，否则减一。如果次数为０，那么需要保存下一个数字，并把次数设为一。最后我们
			要找的数字肯定是最后一次把次数设为１的对应的数字。
	另一种解法可以是，利用partition(即快排的思想)，由于需要找的数字次数超过了一半，排序后这个数字一定是数组的中位数，即下标是n/2.
*/
