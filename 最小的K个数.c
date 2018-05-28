#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

int Partition(int *arr,int len,int left,int right){
    while(left>=right)
        return left;

    int i=left,j=right;
    int key=arr[left];
    while(i<j){
        while(i<j && key < arr[j]){
            j--;
        }
        arr[i]=arr[j];
        while(i<j && key > arr[i]){
            i++;
        }
        arr[j]=arr[i];
    }
    arr[i]=key;
    return i;
}

void GetLeastNumbers(int *nums,int k,int len){

    if(nums==NULL || k > len || len <=0 || k<=0)
        return ;

    int start=0,end=len-1;
    int index=Partition(nums,len,start,end);
    while(index != k-1){            //数组下标是从0开始的，所以是k-1
        if(index<k-1){      //说明最小的第k个数在index右边
            start=index+1;
            index=Partition(nums,len,start,end);
        }else{                  //最小的第k个数在index左边
            end=index-1;
            index=Partition(nums,len,start,end);
        }
    }
    for(int i=0;i<k;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}

int main(){
	int nums[8]={4,5,1,6,2,7,3,8};
	int len=sizeof(nums)/sizeof(int);
	int k;
	printf("input K :");
	scanf("%d",&k);
 //    printf("len=%d\n",);
	GetLeastNumbers(nums,k,len);
	return 0;	
}
