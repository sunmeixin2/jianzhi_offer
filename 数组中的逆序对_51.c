/*
	题目：　在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
			输入一个数组，求出这个数组中的逆序对的总数。
			例如，在数组｛７，５，６，４｝中，一共存在５个逆序对，分别是（７，６），（７，５），（７，４）（６，４）和（５，４）
*/

#include<stdio.h>
#include<string.h>
int InversePairsCore(int *data,int *copy,int start,int end){

	if(start==end){
		copy[start]=data[start];
		return 0;
	}

	int len=(end-start)/2;

	int left=InversePairsCore(copy,data,start,start+len);
	int right=InversePairsCore(copy,data,start+len+1,end);

	//i初始化为前半段最后一个数字的下标
	int i=start+len;
	//j初始化为后半段最后一个数字的下标
	int j=end;
	int indexCopy=end;
	int count=0;
	while(i>=start && j>=start+len+1){
		if(data[i]>data[j]){
			copy[indexCopy--]=data[i--];
			count+=j-start-len;
		}
		else{
			copy[indexCopy--]=data[j--];
		}
	}
	for( ;i>=start;--i){
		copy[indexCopy--]=data[i];
	}

	for( ;j>=start+len+1;--j){
		copy[indexCopy--]=data[j];
	}

	return left+right+count;
}
int InversePairs(int *data,int len){
	if(data==NULL || len<0)
		return 0;
	int copy[len];
	for(int i=0;i<len;i++)
		copy[i]=data[i];

	int count=InversePairsCore(data,copy,0,len-1);

	return count;
}
int main(){
	int data[]={6, 5, 4, 3, 2, 1};
	int len=sizeof(data)/sizeof(int);

	int result=InversePairs(data,len);
	printf("%d\n", result);
	return 0;
}

/*
	题解：利用归并排序的思想，先把数组分割成子数组，统计除子数组内部逆序对的数目，然后在统计出两个相邻子数组之间的逆序对的数目。
		在统计逆序对的过程中，还需要对数组进行排序。
*/