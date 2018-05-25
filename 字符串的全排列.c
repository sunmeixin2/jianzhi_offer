/*
	题目:输入一个字符串，打印出该字符串中字符的所有排列。
	例如：输入字符串abc,则打印出由字符a、b、c所能排列出来的所有字符abc acb bac bca cab和cba	
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Permutation(char *pstr,char *pBegin){
	
	if(*pBegin=='\0'){
		printf("%s\n",pstr);
	}else{
	
		for(char* pch=pBegin;*pch != '\0';++pch){

				char temp=*pch;
				*pch=*pBegin;
				*pBegin=temp;
				
				Permutation(pstr,pBegin+1);
				
				temp=*pch;
				*pch=*pBegin;
				*pBegin=temp;
		
		}
	}
}
int main(){
	char str[]="abc";
	Permutation(str,str);
	return 0;

} 


/*
	题解:	递归思路
		分两步：第一步求出所有可能出现在第一个位置的字符，即把第一个字符和后面所有的字符交换。
				第二步固定第一个字符，求后面所有字符的全排列。
				这时仍把后面的字符分成两部分，第一个字符，以及这个字符后面的所有字符.然后逐一和他后面的字符交换。

*/
