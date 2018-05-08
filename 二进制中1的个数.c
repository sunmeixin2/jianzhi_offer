#include<stdio.h>
int numberOf1(int n){
	int count=0;
//    unsigned int flag=1;
//    while(flag){		//循环的次数等于整数的二进制位数 
//	    if(n&flag)
//	        count++;
//	    flag=flag<<1;
//    }
	
	
//优质解法
	while(n){
		count++;
		n=(n-1)&n;		//把一个数减去1在和他自己做与运算 
	}	 
	
	   
	return count; 
}
int main(){
	
	int n,result;
	scanf("%d",&n);
	//result=numberOf1(n);
	printf("%d",n>>1);
}

/*
	需要考虑负数，负数是用补码表示的， 要保证移位后仍是一个负数，所以不能移动N,
	可以移动flag  先判断最低位，再是次低位......这样反复左移， 
*/ 
