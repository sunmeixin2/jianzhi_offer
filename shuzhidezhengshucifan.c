#include<stdio.h>
#include<stdbool.h> 
bool g_InvalidInput=false;
double Power(double base,int exponent);
double PowerWithUnsignedExponent(double base,unsigned int exponent);
bool equal(double num1,double num2);

bool equal(double num1,double num2){
	if(((num1-num2) > -0.0000001) && ((num1-num2) < 0.0000001)){
		return true;
	}
	else
		return false;
}
double Power(double base,int exponent){
	
	g_InvalidInput=false;
	
	if(equal(base,0.0) && exponent < 0 ){		//底数为0  且指数为负数
		g_InvalidInput=true;
		return 0.0; 
	}
	
	unsigned int absExponent = (unsigned int) (exponent);
	if(exponent < 0){
		absExponent=(unsigned int)(-exponent);
	}
	
	double result=PowerWithUnsignedExponent(base,absExponent);
	
	if(exponent < 0){
		result=1.0/result;
		return result;
	}
	return result;
}

double PowerWithUnsignedExponent(double base,unsigned int exponent){
	int i;
	double result=1.0;
	for(i=1;i<=exponent;i++){
		result*=base;
	}
	return result;
}
main(){
	double val;
	val=Power(0,4);
	printf("val=%lf",val);
}

/*
** 需要考虑到指数小于1 的情况，或 底数为0底数为负数的情况（对0求倒数的情况 ） 
*/



