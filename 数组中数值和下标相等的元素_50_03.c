/*
	题目：假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实
	 现一个函数找出数组中任意一个数值等于其下标的元素。
	 例如，在数组{-3, -1,1, 3, 5}中，数字3和它的下标相等
*/

#include<stdio.h>
#include<string.h>
int GetNumberSameAsIndex(int *data,int len){

	if(data == NULL || len <= 0)
		return -1;

	int left = 0;
	int right = len-1;
	while(left <= right){
		int middle = (left + right)/2;
		if(data[middle] == middle)
			return middle;
		else if(data[middle] > middle)
			right = middle-1;
		else
			left = middle+1;
	}

	return -1;
}
int main()
{
	int data[]= { -3, -1, 1, 3, 5 };
	int len = sizeof(data)/sizeof(int);
	int result = GetNumberSameAsIndex(data,len);
	printf("%d\n", result);
	return 0;
}

/*
	题解：　采用二分查找，如果第ｉ个数字的值ｍ大于ｉ，那么它右边的数字都大于对应的下标，只需从它左边的数字中查找即可。
					　　如果数字的值ｍ小于他的下标，那么它左边的数字都小于对应的下标，只需从它右边的数字中查找即可。
*/