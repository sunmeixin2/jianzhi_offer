#include<stdio.h>
#include<string.h>
void replaceSpace(char *str){
	
	if(str == NULL || strlen(str)<=0){
		return;
	}
	int indexold,indexnew,newlen,count=0;	//count为计算空格数
	int i;
	for(i=0;i<strlen(str);i++){
		if(str[i]==' ')
			++count;
	}
	indexold=strlen(str)-1;		//indexold为替换前的str下标
	newlen=strlen(str)+count*2;	//计算空格转换成%20之后的str长度
	indexnew=newlen-1;	//indexnew为为把空格替换为%20后的str下标

	for(;indexold>=0 ;indexold--){
		if(str[indexold]==' '){
			str[indexnew--]='0';
			str[indexnew--]='2';
			str[indexnew--]='%';
		}else{
			str[indexnew--]=str[indexold];
		}
	}
}
main(){
	int i;
	//测试数据 
	char str[30]="we are happy";
//	char str[30]=" helloworld";	//空格在句子开头 
//	char str[30]="helloworld ";//空格在句子结尾 
//	char str[30]="hello  world";	//连续有两个空格 
//	char str[30]="";	//空串 


	replaceSpace(str);
//	replaceSpace(NULL);	//传入NULL 
	printf("%s",str);
	
}


/*
题目：将一个字符串中的空格替换成“%20”。
	 例如，当字符串为We Are Happy.
	 则经过替换之后的字符串为  We%20Are%20Happy。 
思路：  问题1：替换字符串，是在原来的字符串上做替换，还是新开辟一个字符串做替换！
		问题2：在当前字符串替换，怎么替换才更有效率（不考虑java里现有的replace方法）。
      	从前往后替换，后面的字符要不断往后移动，要多次移动，所以效率低下
      	从后往前，先计算需要多少空间，然后从后往前移动，则每个字符只为移动一次，这样效率更高一点。 
*/



