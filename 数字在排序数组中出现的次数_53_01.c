/*
	题目:统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,3, 3, 4, 5}和数字3，
				由于3在这个数组中出现了4次，因此输出4.
*/

#include<stdio.h>
#include<string.h>
int GetFirstK(int *data,int len,int k,int start,int end){
	if(start > end)
		return -1;
	int middleIndex = (start+end)/2;
	int middleData = data[middleIndex];

	if(middleData == k){
		if((middleIndex > 0 && data[middleIndex - 1] != k) || (middleIndex == 0))
			return middleIndex;
		else
			end = middleIndex - 1;
	}
	else if (middleData > k)
		end = middleIndex - 1;
	else
		start = middleIndex + 1;

	return GetFirstK(data,len,k,start,end);
}
int GetLastK(int *data,int len,int k,int start,int end){
	if(start > end)
		return -1;

	int middleIndex = (start + end)/2;
	int middleData = data[middleIndex];

	if(middleData == k){
		if((middleIndex < len - 1 && data[middleIndex+1] != k) || middleIndex == len - 1 )
			return middleIndex;
		else
			start = middleIndex+1;
	}
	else if(middleData < k)
		start=middleIndex + 1;
	else
		end = middleIndex - 1;

	return GetLastK(data,len,k,start,end);
}
int GetNumberOfK(int *data,int len,int k){

	int number = 0;
	if(data != NULL && len > 0){
		int first = GetFirstK(data,len,k,0,len - 1);
		int last = GetLastK(data,len,k,0,len - 1);

		if(first > -1 && last > -1)
			number = last - first + 1;
	}

	return number;

}
int main(){
   
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    int len = sizeof(data)/sizeof(int);
	int k;
	printf("input k:");
	scanf("%d",&k);
	int result = GetNumberOfK(data,len,k);
	printf("%d\n",result);
	return 0;
}

/*
	题解：数组是排序的，所以可以用二分查找算法，先拿数组中间的数字和Ｋ比较。如果中间的数字比Ｋ大，那么Ｋ只有可能出现在数组的前半段，
	如何比Ｋ大，则在数组后半段。如果相等，先判断这个数字是不是第一个Ｋ。如果中间数字的前一个数字不是Ｋ，那么此时中间的数字刚好就是第一个Ｋ。
	如果是，则继续在前半段找到第一个Ｋ。同理找到数组中的最后一个Ｋ。
*/