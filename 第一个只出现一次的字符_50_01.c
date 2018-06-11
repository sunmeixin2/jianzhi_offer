/*
	题目：在字符串中找出第一个只出现一次的字符。如输入“abaccdeff”,则输出"b"。
*/

#include<stdio.h>
#include<string.h>
#include<memory.h>
char FirstNotRepeating(char *pstr){

	if(pstr == NULL)
		return '\0';
	int tableSize=256;
	unsigned int hashTable[tableSize];

	memset(hashTable,0,tableSize*sizeof(int));
    // for(unsigned int i = 0; i < tableSize; ++i)
    //     hashTable[i] = 0;

	char *pHashKey=pstr;

	while(*(pHashKey) != '\0')
		hashTable[*(pHashKey++)]++;
	pHashKey=pstr;
	while(*pHashKey != '\0'){
		if(hashTable[*pHashKey] == 1)
			return *pHashKey;
		pHashKey++;
	}
	return '\0';

}
int main(){
	char *str="abaccdeff";
	char result;
	result=FirstNotRepeating(str);
	printf("%c\n", result);
	return 0;
}
/*
	题解：　采用哈希表，时间复杂度位O(n).
		因为需要一个包含２５６个字符的辅助数组，他的大小是１ＫＢ。由于数组的大小是一个常数，因此空间复杂度是Ｏ(1).
*/
