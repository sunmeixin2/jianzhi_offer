/**
	 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
		的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
*/

#include<stdio.h>
#include<string.h>
int FindNumbersWithSum(int *data,int len,int sum ,int *num1,int *num2){

	int found = 0;
	if(data == NULL || len <= 0)
		return found;
	int p1,p2;
	p1 = 0;
	p2 = len-1;

	while(p1 < p2){
		long long curSum = data[p1] + data[p2];

		if(curSum == sum){
			*num1 = data[p1];
			*num2 = data[p2];
			found = 1;
			break;
		}
		else if(curSum < sum)
			p1++;
		else
			p2--;
	}

	return found;
}
int main(int argc, char const *argv[])
{
	int data[] = {1, 2, 4, 7, 11, 16};
	int sum;
	int num1,num2;
	int len = sizeof(data)/sizeof(int);
	printf("input sum :");
	scanf("%d",&sum);
	int result = FindNumbersWithSum(data,len,sum,&num1,&num2);
	if(result){
		printf("%d,%d\n", num1,num2);
	}else{
		printf("No\n");
	}
	return 0;
}

/**
	题解：　定义两个指针，分别指向数组的头和尾，比较两个指针所指向数字的和与ｓ的大小,如果和等于s，则找到了两个数字。
			如果和小于s，移动数字较小的指针，使Ｐ１＋＋，继续比较。
			如果和大于s,移动数字较大的指针，是Ｐ２－－，继续比较，直到和相等，停止比较。
*/