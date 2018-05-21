

/*
  ������3�����������޸������ҳ��ظ�������
  ��Ŀ����һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ�������������
  ����һ���������ظ��ġ����ҳ�����������һ���ظ������֣��������޸������
  ���顣���磬������볤��Ϊ8������{2, 3, 5, 4, 3, 2, 6, 7}����ô��Ӧ��
  ������ظ�������2����3��

*/


#include<stdio.h>
int getDuplication(const int* nums,int len){
	if(nums == NULL || len<=0){
		return -1;
	}
	int i;
	for(i=0;i<len;i++){
		if(nums[i]<=0 || nums[i]>=len){
			return -1;
		}
	}
	int start=1;
	int end=len-1;
	while(end>=start){
		int middle=(end+start)/2;
		//int middle=((end-start)>>1)+start;
		int count=countRange(nums,len,start,middle);
		if(end==start){
			if(count>1)
				return start;
			else
				break;
		}
		if(count > (middle-start+1)){
			end=middle;
		}
		else
			start=middle+1;
	}
	return -1;
}
int countRange(const int* nums,int len,int start,int end){
	int i;
	if(nums == NULL)
		return 0;
	int count=0;
	for(i=0;i<len;i++){
		if(nums[i]>=start && nums[i]<=end){
			count++;
		}
	}
	printf("count:%d\n",count);
	return count;
}
main(){
//	int nums[] = { 1, 2, 3, 4, 5, 6, 7, 4};
//	int nums[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
//	int nums[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
	int nums[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
//	int nums[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
//	int nums[] = { 1, 1 };
	//int nums[]={2,3,5,4,2,3,6,7};
	int value;
	value=getDuplication(nums,sizeof(nums)/sizeof(int));
	printf("value:%d",value);
}



