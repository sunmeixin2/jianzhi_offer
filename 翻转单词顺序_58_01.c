/**
	题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
 	为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
 	则输出"student. a am I"。
*/

#include<stdio.h>
#include<string.h>
void Reverse(char *pbegin,char *pend){
	if(pbegin == NULL ||  pend == NULL )
		return;
	char temp;
	while(pbegin < pend)
	{

		temp = *pbegin;
		*pbegin = *pend;
		*pend = temp;

		pbegin++,pend--;
	}
}

char *ReverseSentence(char *pdata){
	if(pdata == NULL)
		return NULL;

	char *pbegin = pdata;

	char *pend = pdata;
	while(*pend != '\0')
		pend++;
	--pend;

	Reverse(pbegin,pend);	//翻转整个句子


	//翻转句子中的每个单词
	pbegin = pend = pdata;
	while(*pbegin != '\0'){

		if(*pbegin == ' '){
			pbegin++;
			pend++;

		}
		else if(*pend == ' ' || *pend == '\0'){
			Reverse(pbegin,--pend);
			pbegin = ++pend;
		}
		else{
			pend++;
		}
	}

	return pdata;
}
int main(){
	char pdata[]="I am a student.";
	char *result = NULL;
	printf("%s\n", pdata);
	result = ReverseSentence(pdata);
	printf("%s\n", result);
	return 0;
}


/**
	题解：第一步翻转句子中所有的字符，比如“.tneduts a ma I”，此时不但翻转了句子中单词的顺序，连单词内的字符顺序也被翻转。
			第二步在翻转每个单词中字符的顺序，就得到了“student. a am I”.

			注意　指针与数组的关系，小心出现段错误的问题。

*/