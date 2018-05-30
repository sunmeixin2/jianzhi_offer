/*
	题目：输入一个整数Ｎ，求1~n这n个整数的十进制表示中１出现的次数。
		例如，输入12,1~12这些整数中包含1的数字有1 10 11 和12,1一共出现了5次
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int PowerBase10(unsigned int n){
	int result=1;
	for(int i=0;i<n;i++){
		result*=10;
	}
	return result;
}
int NumberOf1(char *strN){
	if(strN==NULL || *strN<'0' || *strN >'9' || *strN=='\0')
		return 0;
	int first=*strN-'0';
	unsigned int len=strlen(strN);
	
	if(len==1 && first ==0)
		return 0;
	if(len==1 && first >0)
		return 1;

	//假设strN是“21345”	
	//numFirstDigit 是数字10000~19999的第一位中的数目
	int numFirstDigit=0;
	if(first>1)
		numFirstDigit=PowerBase10(len-1);
	else if(first==1)
		numFirstDigit=atoi(strN+1)+1;	//atoi(const char *str) 把参数str所指向的字符串转换为一个整数（int）
	
	//numOtherDigits是1346~21345除第一位之外的数位中的数目
	int numOtherDigits=first*(len-1)*PowerBase10(len-2);
	//numberRecursize是1~1345中的数目
	int numRecursive=NumberOf1(strN+1);

	return numFirstDigit+numOtherDigits+numRecursive;
}
int NumberOfBetween1AndN(int n){
	if(n<=0)
		return 0;
	char strN[50];
	sprintf(strN,"%d",n);
	
	return NumberOf1(strN);

}
int main(){
	int n;
	int result;
	printf("input N:");
	scanf("%d",&n);
	result=NumberOfBetween1AndN(n);
	printf("%d\n",result);
	return 0;
}
