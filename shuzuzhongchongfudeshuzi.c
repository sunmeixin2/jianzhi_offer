
/*

	������3��һ�����ҳ��������ظ�������
	��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
	Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
	��ô��Ӧ��������ظ�������2����3��

*/ 

#include<stdio.h>
#include<stdbool.h>
bool duplicate(int nums[],int len,int* duplication){
	int temp;
	int i;
	if(nums == NULL || len<=0){
		return false;
	}
	for(i=0;i<len;i++){
		if(nums[i]<0 || nums[i]>len-1){
			return false;
		}
	}
	
	for(i=0;i<len;i++){
		while(nums[i] != i){
			if(nums[i] == nums[nums[i]]){
				*duplication=nums[i];
				return true;
			}
			
			//����nums[i]��nums[nums[i]] 
			temp=nums[i];
			nums[i]=nums[temp];
			nums[temp]=temp;
		}
	}
	return false;
}
main(){
	int arr[]={2,3,1,0,2,5,3};
	int duplication;
	int len=sizeof(arr)/sizeof(int);
	duplicate(arr,len,&duplication);
	printf(" nums:%d",duplication);
}
