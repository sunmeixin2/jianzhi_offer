#include<stdio.h>
int numberOf1(int n){
	int count=0;
//    unsigned int flag=1;
//    while(flag){		//ѭ���Ĵ������������Ķ�����λ�� 
//	    if(n&flag)
//	        count++;
//	    flag=flag<<1;
//    }
	
	
//���ʽⷨ
	while(n){
		count++;
		n=(n-1)&n;		//��һ������ȥ1�ں����Լ��������� 
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
	��Ҫ���Ǹ������������ò����ʾ�ģ� Ҫ��֤��λ������һ�����������Բ����ƶ�N,
	�����ƶ�flag  ���ж����λ�����Ǵε�λ......�����������ƣ� 
*/ 
