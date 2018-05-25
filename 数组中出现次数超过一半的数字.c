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
	int nums[9]={1,2,3,2,5,4,5,4,2};
	int len=sizeof(nums)/sizeof(int);
	int result;
	result=MoreThanHalfNum(nums,len);
	printf("%d\n",result);
	return 0;
}
