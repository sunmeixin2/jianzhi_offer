#include <stdio.h>
 
void swap(int *a, int *b);
void adjustHeap(int param1,int j, int inNums[]);
void  HeapSort(int nums, int inNums[]);
//大根堆进行调整
void adjustHeap(int param1, int j, int inNums[])
{
    int temp=inNums[param1];
    int k;
    for(k=param1*2+1;k<j;k=k*2+1)
    {
        //如果右边值大于左边值，指向右边
        if (k+1<j && inNums[k]< inNums[k+1])
        {
            k++;
        }
        //如果子节点大于父节点，将子节点值赋给父节点,并以新的子节点作为父节点（不用进行交换）
        if (inNums[k]>temp)
        {
            inNums[param1]=inNums[k];
            param1=k;
        }
        else
            break;
    }
        //put the value in the final position
    inNums[param1]=temp;
}
//堆排序主要算法
void HeapSort(int nums,int inNums[])
{
	int i,j;
    //1.构建大顶堆
    for (i=nums/2-1;i>=0;i--)
    {
                //put the value in the final position
        adjustHeap(i,nums,inNums);
    }
    //2.调整堆结构+交换堆顶元素与末尾元素
    for ( j=nums-1;j>0;j--)
    {
                //堆顶元素和末尾元素进行交换
        int temp=inNums[0];
        inNums[0]=inNums[j];
        inNums[j]=temp;
 
        adjustHeap(0,j,inNums);//重新对堆进行调整
    }
}
int main() {
    int data[] = {6,5,8,4,7,9,1,3,2};
    int len = sizeof(data) / sizeof(int);
    HeapSort(len,data);
    return 0;
}


















//#include<stdio.h>
//#define MAX 6
//void Headadjust(int k[],int s,int n){
//	int temp,i;
//	temp=k[s];
//	for(i=s*2;i<n;i=i*2){
//		if(i<n && k[i]>k[i+1]){
//			i++;
//		}
//		if(temp <= k[i]){
//			break;
//		}
//		k[s]=k[i];
//		s=i;
//	}                                                                          
//	k[s]=temp;
//}
//void Headsort(int k[],int n){
//	int i;
//	for(i=n/2;i>1;i--){			//建初始堆 
//		Headadjust(k,i,n);
//	}
//	for(i=n;i>=2;i++){
//		k[0]=k[i];
//		k[i]=k[1];
//		k[1]=k[0];
//		Headadjust(k,1,i-1);
//	}
//}
//main(){
//	int nums[MAX]={-1,5,3,2,4,1};
//	int i;
//	Headsort(nums,MAX-1);
//	printf("排序后：");	
//	for(i=1;i<MAX;i++){
//		printf("%d ",nums[i]);
//	}
//}
