/*
	题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
	 找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

	 例如，输入数组｛２，４，３．６，３，２，５，５｝，只有４和６出现了一次
*/

#include<stdio.h>
#include<string.h>
unsigned int FindFirstBitIs1(int num){

	int indexBit=0;

	while((num & 1) == 0){		//判断最后一位是不是１
		indexBit++;
		num = num >> 1;
	}

	return indexBit;
}
int IsBit1(int num,unsigned int indexBit){
	num = num >> indexBit;
	return (num & 1);
}
void FindNumsAppearOnce(int *data,int len,int* num1,int* num2){

	if(data == NULL || len < 2)
		return;
	int result_or=0;		//　两个只出现一次的数字的异或结果

	for(int i=0;i<len;i++)
		result_or ^=data[i];	//	对整个数组异或

	unsigned int indexOf1 = FindFirstBitIs1(result_or);		//　　找出第一个为１的位置

	*num1 = *num2 = 0;

    for(int j = 0; j < len; ++j)
    {
        if(IsBit1(data[j], indexOf1))		//　分组后的数组进行异或
            *num1 ^= data[j];
        else
            *num2 ^= data[j];
    }

}
int main(){
	int data[] = {2,4,3,6,3,2,5,5};
	int len = sizeof(data)/sizeof(int);
	int num1,num2;
	FindNumsAppearOnce(data,len,&num1,&num2);
	printf("%d\n", num1);
	printf("%d\n", num2);
	return 0;
}

/*
	题解：根据数组的特点，可以先考虑这个数组中只有一个数字只出现了一次，其他数字都出现了两次，该怎么找这个数字？
		异或运算的性质：任何一个数字异或它自己都等于０，可以从头到尾异或数组中的每个数字，最终的结果就是只出现一次的数字。

		接下来把原数组分为两个子数组，使得每个子数组包含一个只出现一次的数字，而其他数字都成对出现两次。
		分子数组的过程为：对整个数组异或，最后结果为两个只出现一次的数字的异或结果，在结果数字中找出第一个为１的位置，记为n。
		我们以第n位是不是１划分数组。
		最后对每个子数组进行异或可以得到两个只出现一次的数字。

*/