#include<stdio.h>
int Power(double base,int exponent){
	int i;
	double result=1.0;

	if(base==0 && exponent<0)
		return 0.0;
	
	unsigned int absExponent=(unsigned int)(exponent);

	if(exponent<0)
		absExponent=(unsigned int)(-exponent);
	
	for(i=1;i<=absExponent;i++)
		result=result*base;
	if(exponent<0)
		result=1.0/result;
//	printf("%lf\n",result);
	return result;
}
int main(){
	double base;
	int exponent;
	double val=1.0;
	scanf("%lf %d",&base,&exponent);
	val=Power(base,exponent);
	printf("%lf",val);
	return 0; 
}

/*
** ��Ҫ���ǵ�ָ��С��1 ��������� ����Ϊ0����Ϊ�������������0��������� �� 
*/
