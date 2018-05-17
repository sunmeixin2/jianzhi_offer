/*
	题目：输入数字N，按顺序打印出从1到最大的N位数十进制数。比如输入3，则打印出1、2、3....999 
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
	while(!Increment(number)){		//循环遍历每一个数字知道最大的N位数结束 
		PrintNumber(number);
	}
}
bool Increment(char *number){
	bool isOverflow=false;		//true表示已经到达最大N位数了，因此为 Print1ToMaxOfNDigits函数中while的结束条件 
	int nTakeOver=0;		//代表进位 
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
	思路：由于需要考虑N的范围，所以当N很大的时候，求最大的N位数使用int 或long long都会溢出，
	所以需要使用字符串来保存数据。
		每个字符都是'0'~'9'之间的 一个字符，用来表示数字中的一位。因为数字最大是N位，
		因此需要一个长度为N+1的字符串（最后一位是'\0'）.当实际数字位数不够N位的时候，在字符串的前半部分补0。  
*/
