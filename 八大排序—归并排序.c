#include<stdio.h>
#include<stdlib.h>
void Merge(int *arr,int first,int mid,int last,int *temp ){
	int i=first,j=mid+1;
	int n= mid,m = last;
	int k=0;
	while(i<=n && j<=m){
		if(arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while(i<=n){
		temp[k++] = arr[i++];
	}
	while(j<=m){
		temp[k++] = arr[j++];
	}
	j=0;
	for(i=0;i<k;i++){
		arr[first+i] = temp[i];
	}
}
void MergeSort(int *arr,int first, int last,int *temp){
	if(first < last){
		int mid = (first+last)/2;
		MergeSort(arr,first,mid,temp);		//左边有序	 
		MergeSort(arr,mid+1,last,temp);		//右边有序 
		Merge(arr,first,mid,last,temp);		//将两个有序序列合并 
	}
}
int main(){
	//int arr[] = {24,35,12,57,48,66,73,21,34,33};
	int arr[] = {12,24,5,8,3,9,11,7};
	int len = sizeof(arr)/sizeof(int);
	int temp[len];
	int i;
	MergeSort(arr,0,len-1,temp);
	for(i=0;i<len;i++){
		printf("%d ",arr[i]);
	} 
	return 0;
} 
