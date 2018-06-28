/**
	题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
	 	请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数字2，
	 	该函数将返回左旋转2位得到的结果"cdefgab"。

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
char* LeftRotateString(char *pstr,int n,int len){
	if(pstr != NULL){
		
		if(len > 0 && n > 0 && n<len){
			
			//翻转字符串前n个字符
			Reverse(pstr,pstr+n-1);
			//翻转字符串的后面部分
			Reverse(pstr+n,pstr+len-1);
			//翻转整个字符串
			Reverse(pstr,pstr+len-1);

		}
	}
	return pstr;
}
int main(int argc, char const *argv[])
{
	char pstr[]="abcdefg";
	int len,n;
	char *result=NULL;

	printf("input n:");
	scanf("%d",&n);

	len=strlen(pstr);

	result=LeftRotateString(pstr,n,len);
	printf("%s\n", result);
	return 0;
}

/**
	题解：以"abcedfg"
		可以从上一个问题得到启发，先将字符串按照输入的数字分为前半部分和后半部分，
		　接下来分别将前半部分和后半部分翻转，翻转后字符串为“bagfedc”,
			最后翻转整个字符串　，得到"cdefgab".
*/
