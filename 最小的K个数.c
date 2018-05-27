#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int RandomInRange(int min, int max)
{
    int random = rand() % (max - min + 1) + min;
    return random;
}

void Swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int Partition(int data[], int length, int start, int end)
{
    // if(data == nullptr || length <= 0 || start < 0 || end >= length)
    //     throw new std::exception("Invalid Parameters");
   
    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]);

    int small = start - 1;
    for(index = start; index < end; ++ index)
    {
        if(data[index] < data[end])
        {
            ++ small;
            if(small != index)
                Swap(&data[index], &data[small]);
        }
    }

    ++ small;
    Swap(&data[small], &data[end]);

    return small;
}
void GetLeastNumbers(int* input, int n, int k)
{
    // if(input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0)
    //     return;
  
    int start = 0;
    int end = n - 1;
    int index = Partition(input, n, start, end);
    while(index != k - 1)
    {
        if(index > k - 1)
        {
            end = index - 1;
            index = Partition(input, n, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(input, n, start, end);
        }
    }

    // for(int i = 0; i < k; ++i)
    //     printf("%d ", input[i]);
}

// int Partition1(int *arr,int len,int left,int right){

// 	int i=left,j=right;
// 	int index=RandomInRange(left,right);
// 	int key=arr[index];
// 	while(i<j){
// 		while(i<j && key < arr[j]){
// 			j--;
// 		}
// 		arr[i]=arr[j];
// 		while(i<j && key > arr[i]){
// 			i++;
// 		}
// 		arr[j]=arr[i];
// 	}
// 	arr[i]=key;
// 	return i;
// }

// void GetLeastNumbers1(int *nums,int k,int len){

// 	if(nums==NULL || k > len || len <=0 || k<=0)
// 		return ;
// 	int start=0,end=len-1;
// 	int index=Partition(nums,len,start,end);
// 	while(index != k-1){			//数组下标是从0开始的，所以是k-1
// 		if(index<k-1){		//说明最小的第k个数在index右边
// 			start=index+1;
// 			index=Partition(nums,len,start,end);
// 		}else{					//最小的第k个数在index左边
// 			end=index-1;
// 			index=Partition(nums,len,start,end);
// 		}
// 	}
// 	for(int i=0;i<k;i++){
// 		printf("%d ",nums[i]);
// 	}
// 	printf("\n");
// }
int main(){
	int nums[]={4,5,1,6,2,7,3,8};
	int len=sizeof(nums)/sizeof(int);
	int k;
	printf("input K :");
	scanf("%d",&k);
    printf("%d\n",k);
    printf("00\n");
	GetLeastNumbers(nums,k,len);
	return 0;	
}
