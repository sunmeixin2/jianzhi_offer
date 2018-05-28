/*
    题目：输入Ｎ个整数，找出其中最小的Ｋ个数。例如，输入４，５，１，６，２，７，３，８这８个数字，则最小的４个数字是１，２，３，４
*/

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
	GetLeastNumbers(nums,k,len);
	return 0;	
}


/*
    题解：
        法１：可以基于快排思想的partition()函数来解决。如果基于数组的第Ｋ个数字来调整，则使得比第Ｋ个数字小的所有数字都位于数组的左边，
                比第Ｋ个数字答的所有数字都位于数组的右边。这样，位于数组中左边的Ｋ个数字就是最小的Ｋ个数字（不一定是排序的）。
        法２：
*/