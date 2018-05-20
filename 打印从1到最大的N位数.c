/*
	��Ŀ����������N����˳���ӡ����1������Nλ��ʮ����������������3�����ӡ��1��2��3....999 
*/ 

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigits(int n);

void Print1ToMaxOfNDigits(int n){
	if(n<=0)
		return;
	char number[n+1];
	memset(number,'0',n);
	number[n]='\0';
	while(!Increment(number)){		//ѭ������ÿһ������֪������Nλ������ 
		PrintNumber(number);
	}
}
bool Increment(char *number){
	bool isOverflow=false;		//true��ʾ�Ѿ��������Nλ���ˣ����Ϊ Print1ToMaxOfNDigits������while�Ľ������� 
	int nTakeOver=0;		//�����λ 
	int len=strlen(number);
	int i;
	for(i=len-1;i>=0;i--){
		int nSum=number[i]-'0'+nTakeOver;
		if(i==len-1){
			nSum++;
		} 
		if(nSum>=10){
			if(i==0){
				isOverflow=true;
			}else{
				nSum-=10;
				nTakeOver=1;
				number[i]=nSum+'0';
			}
			
		}else{
			number[i]='0'+nSum;
			break;
		}
	}
	return isOverflow;
}

void PrintNumber(char *number){
	bool isPrex0=true;
	int len=strlen(number);
	int i;
	for(i=0;i<len;i++){
		if(isPrex0 && number[i]!='0'){
			isPrex0=false;
		}
		if(!isPrex0){
			printf("%c",number[i]);
		}
	}
	printf("\t");
}
int main(){
	
	Print1ToMaxOfNDigits(3);
	return 0;
} 

/*
	˼·��������Ҫ����N�ķ�Χ�����Ե�N�ܴ��ʱ��������Nλ��ʹ��int ��long long���������
	������Ҫʹ���ַ������������ݡ�
		ÿ���ַ�����'0'~'9'֮��� һ���ַ���������ʾ�����е�һλ����Ϊ���������Nλ��
		�����Ҫһ������ΪN+1���ַ��������һλ��'\0'��.��ʵ������λ������Nλ��ʱ�����ַ�����ǰ�벿�ֲ�0��  
*/
