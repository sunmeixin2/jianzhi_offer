#include<stdio.h>
#include<string.h>

int MinInOrder(int *nums,int index1,int index2){
	int i;
	int result=nums[index1];
	for(i=index1+1;i<=index2;i++){
		if(result>nums[i]){
			result=nums[i];
		}
	}
	return result;
}
int Min(int *nums,int len){
	
	if(nums==NULL || len<=0){
		return ;
	}
	
	int index1,index2,indexMid;
	index1=0;
	index2=len-1;
	indexMid=index1;
	while(nums[index1]>=nums[index2]){
		
		if(index2-index1==1){
			indexMid=index2;
			break;
		}
	
		indexMid=(index1+index2)/2;
		
		if(nums[index1]==nums[indexMid] && nums[index2]==nums[indexMid]){		//如果index1 index2 indexMid 下标相同，顺序查找 
			return MinInOrder(nums,index1,index2); 
		}	
		if(nums[indexMid]>=nums[index1]){
			index1=indexMid;
		}
		else if(nums[indexMid]<=nums[index2]){
			index2=indexMid;
		}
		
	}
	return nums[indexMid];
}


int main(){
	int val;
	//int nums[]={3,4,5,1,2};
//	int nums[]={1,2,3,4,5};
	int nums[]={1,0,1,1,1};
//	int nums[]={1,1,1,0,1};
	int len=sizeof(nums)/sizeof(int);
	//printf("%d",len);
	
	val=Min(nums,len);
	printf("%d",val);
	return 0;
	
} 
