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
	
	if(equal(base,0.0) && exponent < 0 ){		//����Ϊ0  ��ָ��Ϊ����
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
** ��Ҫ���ǵ�ָ��С��1 ��������� ����Ϊ0����Ϊ�������������0��������� �� 
*/



