/*
	题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
	 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
	 4～6和7～8。
*/

#include<stdio.h>
#include<string.h>

void printContinuousSequence(int small,int big){

	for(int i=small; i<= big;i++){
		printf("%d ", i);
	}
	printf("\n");
}
void FindContinuousSequence(int sum){

	if(sum < 3)
		return;

	int small = 1;
	int big = 2;
	int middle = (1+sum)/2;
	int curSum = small + big; 

	while(small < middle){

		if(curSum == sum)
			printContinuousSequence(small,big);

		while(curSum > sum && small < middle){
			curSum -= small;
			small++;

			if(curSum == sum)
				printContinuousSequence(small,big);
		}

		big++;
		curSum += big;
	}
}
int main(){

	int sum;

	printf("input sum:");
	scanf("%d",&sum);
	FindContinuousSequence(sum);
	return 0;
}

/**
	题解：　用small 和big 分别表示序列的最大值和最小值。先把small初始化为1,big 初始化为2。
			如果从small到big的序列和大于s ,则可以从序列中去掉较小的值，也就是增大small的值。
			如果从small到big的序列的和小于s，则可以增大big，让这个序列包含跟多的数字。
			因为这个序列至少要有两个数字，我们一直增加smalla到（1+s)/2为止。
*/