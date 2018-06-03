/*
	题目：　数字以0123456789101112131415...的格式序列化到一个字符序列中。在这个序列中，第５位（从0开始计数）是５，
			第１３位是１，第１９位是４，等等。请写一个函数，求任意第Ｎ位对应的数字。
*/

#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int countOfIntegers(int digits){		//　得到Ｍ位的数字总共有多少个

	if(digits==1)
		return 10;
	int count=(int)pow(10,digits-1);
	return  9*count;
}
int beginNumber(int digits){		//Ｍ位数的第一个数字，即两位数是１０，三位数是１００
	if(digits == 1)
		return 0;
	return pow(10,digits-1);
}
int digitsAtIndex_digits(int index,int digits){		//知道要找的那一位数字位于某Ｍ位数之中后
	int number=beginNumber(digits)+index/digits;
	int indexFromRight=digits-index % digits;
	for(int i=1;i<indexFromRight;++i){
		number/=10;
	}
	return number % 10;
}
int digitAtIndex(int index){
	if(index <0 )
		return -1;
	int digits=1;	//数字位数
	while(true){
		int numbers=countOfIntegers(digits);
		if(index<numbers * digits)
			return digitsAtIndex_digits(index,digits);
		index -= digits *numbers;
		digits++;
	}
	return -1;

}
int main(){
	int index;
	int result;
	printf("please input index:");
	scanf("%d",&index);
	result=digitAtIndex(index);
	printf("result=%d\n",result);
	return 0;
}



/*
	假设序列的第１００１位是什么
	思路：一位的数字是０～９　　　　　共１０个数字	　　１０位	１００１在１０个数字之后，即１００１－１０＝９９１
		　两位的数字是１０～９９　　　共９０个	　		１８０位　　９９１＞１８０　再跳过９０个两位数，继续从后面找９９１－１８０＝８１１位
		　三位的数字是１００～９９９　共９００个　　　　２７００位　　８１１＜２７００　所以８１１位是某个三位数中的一位，由于811=270*3+1,
																因此第811位是从100开始的第270个数字即370的中间一位，即７。
*/



