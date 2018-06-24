/*
	题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请找出那个吃出现一次的数字。
*/

#include<stdio.h>
#include<string.h>
int FindNumberAppearingOnce(int *nums,int len){

	if(nums == NULL || len <= 0)
		return -1;

	int bitSum[32] = {0};
	for (int i = 0; i < len; ++i)
	{
		int bitMask=1;
		for (int j = 31; j >= 0; --j)
		{
			int bit = nums[i] & bitMask;
			if(bit != 0)
				bitSum[j] += 1;
			bitMask = bitMask << 1;
		}
	}

	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		result = result << 1;
		result += bitSum[i] % 3;
	}

	return result;
}
int main(int argc, char const *argv[])
{
	int nums[] = { 1, 1, 2, 2, 2, 1, 3};
	int len = sizeof(nums)/sizeof(int);
	int result = FindNumberAppearingOnce(nums,len);
	printf("%d\n", result);
	return 0;
}

/**
	题解：如果一个数字出现三次，那么他的二进制表示的每一位（０或１）也出现三次。如果把所有出现三次的数字的二进制的每一位都分别加起来，
		那么每一位的和都能被３整除。
		把数组中所有数字的二进制表示的每一位都加起来。如果某一位的和能被３整除，那么那个只出现一次的数字二进制表示中对应的那一位是０，
		否则是１。
*/