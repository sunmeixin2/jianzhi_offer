/*
	题目：我们把只包含因子２，３和５的数称作丑数。求按从小到大的顺序的第１５００个丑数。
		例如，６，８都是丑数，但１４不是，因为它包含因子７。习惯上我们把１当作第一个丑数。
*/


#include<stdio.h>
int Min(int a,int b,int c){
	int min=(a < b) ? a : b;
	min=(min < c) ? min : c;
	return min;
}
int GetUglyNumber(int index){
	if(index<0)
		return 0;
	int pUglyNumbers[index];
	pUglyNumbers[0]=1;
	int nextUglyIndex=1;

	int *pMultiply2=pUglyNumbers;
	int *pMultiply3=pUglyNumbers;
	int *pMultiply5=pUglyNumbers;

	while(nextUglyIndex < index){
		int min=Min(*pMultiply2*2,*pMultiply3*3,*pMultiply5*5);
		pUglyNumbers[nextUglyIndex]=min;

		while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
			++pMultiply2;
		while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
			++pMultiply3;
		while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
			++pMultiply5;

		++nextUglyIndex;
	}

	int ugly = pUglyNumbers[nextUglyIndex-1];
	return ugly;
}
int main(){
	int index;
	printf("input index:");
	scanf("%d",&index);
	int result=GetUglyNumber(index);
	printf("%d\n", result);
	return 0;
}

/*
	题解：　方法一　逐个判断每个整数是不是丑数。如果一个丑数能被２整除，就连续除以２；
		如果能被３整除，那么就连续除以３，同理５．如果最后得到是１，那么这个数就是丑数，否则不是。

		方法二：设置一个数组，假设数组中已经有若干排好序的丑数，并且把最大的丑数记为Ｍ。
			接下来把已有的每个丑数乘以２，在乘以２的时候，能得到若干个小于或等于Ｍ的结果，由于小于或等于Ｍ肯定已经在数组中了，所以不考虑。
			还会得到若干大于Ｍ的结果，但只需考虑第一个大于Ｍ的结果。同理３和５．
			
*/