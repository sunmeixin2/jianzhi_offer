/*
	题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
	 都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
	 中，请找出这个数字
*/

#include<stdio.h>
#include<string.h>
int GetMissingNumber(int *data,int len){

	if(data == NULL || len <= 0)
		return -1;

	int left = 0;
	int right = len - 1;

	while(left <= right){
		 int middle = (left + right)/2;
		 if(data[middle] != middle){
		 	if(middle == 0 || data[middle - 1] == middle - 1)
		 		return middle;
		 	right = middle-1;
		 }
		 else
		 	left = middle + 1;
		 
	}

	if(left == len)
		return len;

	//无效的输入，比如数组不是按要求排序的，或者有数字不在０～Ｎ－１范围之内
	return -1;
}
int main(){
	int numbers[] = { 1, 2, 3, 4, 5 };
	int len=sizeof(numbers)/sizeof(int);
	int result=GetMissingNumber(numbers,len);
	printf("%d\n", result);
	return 0;
}

/*
	题解：方法一　想用公式n(n-1)/2求出数字０～n-1的所有数字之和,记为s1。接着求出数组中所有数字之和，记为s2。
				那个不在数组中的数字就是s1-s2的差。这种解法需要O(n)的时间求数组中所有数字的和。

	　方法二　利用数组是递增排序的特点。假设Ｍ不在数组中，那么Ｍ＋１在下标位Ｍ的位置，Ｍ＋２在下标为Ｍ＋１的位置，以此类推。
		采用二分查找算法，如果中间元素的值和下标相等，下轮只需查找数组右边；如果不相等，且它前面一个元素和它下标相等，
		则意味着这个中间的数字正好是第一个值和下标不相等的元素，它的下标就是要找的Ｍ；如果中间元素和下标不相等，且前一个和它的下标
		也不相等，这意味着下一轮在数组左半边查找。

*/