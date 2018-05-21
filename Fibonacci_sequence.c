#include<stdio.h>

int Fibonacci(unsigned n){
	
	int result[2]={0,1};
	int f1=1,f2=0,f=0,i;
	if(n<2){
		return result[n];
	}
	for(i=2;i<=n;i++){
		f=f1+f2;
		
		f2=f1;
		f1=f;
	//	printf("%d ",f);
	}
	return f;
}
int main(){
	
	int n,result=0;
	scanf("%d",&n);
	result=Fibonacci(n);
	printf("%d",result);
	return 0;
}
/*
	*斐波那契数列，类似的题目还有2*1矩阵覆盖、青蛙跳台阶
	青蛙跳台阶可扩展出变态青蛙跳台阶，如青蛙一个可跳1.2...n个台阶，规律是f(n)=2f(n-1) 
*/ 
