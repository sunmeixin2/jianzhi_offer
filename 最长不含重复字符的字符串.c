/*
	题目：请从字符串中找到一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。假设字符串中只包含‘a~z'的字符。
		　例如，在字符串“arabcacfr”中，最长的不含重复字符的子字符串是“acfr”,长度为４．
*/

#include<stdio.h>
#include<string.h>
int longestSubstringWithoutDuplication(char *str,int len){

	int curlen=0;
	int maxlen=0;

	int position[26];   //此数组用于记录字符在字符串中的位置
	for (int i = 0; i < 26; ++i)
		position[i]=-1;
	for (int i = 0; i < len; ++i)
	{
		int prevIndex=position[str[i]-'a'];
		if(prevIndex <0 || i-prevIndex > curlen ){  //第i个字符之前没出现过，或d>f(i+1) 即情况二
				++curlen;			//f(i)=f(i-1)+1			
		}else{
			if(curlen > maxlen)
				maxlen=curlen;
			curlen=i-prevIndex;					//f(i)=d 
		}
		position[str[i]-'a']=i;
	}
	if(curlen > maxlen)
		maxlen=curlen;
	return maxlen;
}
int main(){
	char str[100];
	scanf("%s",str);
	int len=strlen(str);
	int result=longestSubstringWithoutDuplication(str,len);
	printf("%d\n", result);
	return 0;
}

/*
	题解：采用动态规划的思想，首先定义f(i)表示以第i个字符为结尾的不包含重复字符的子字符串的最长长度。
		　如果第i个字符之前没有出现过，那么f(i)=f(i-1)+1。
		　如果第i个字符之前已经出现过，第i个字符和它上次出现在字符串中的位置的距离记为d。
		　接下来分两种情况：一：若 d<=f(i-1),此时第i个字符上次出现在f(i-1)对应的最长子字符串之中，因此f(i)=d。
		　二：d>f(i-1),此时第i个字符上次出现在f(i-1)对应的最长自字符串之前，因此仍然有f(i)=f(i-1)+1。
*/