#include<stdio.h>
#include<stdbool.h>
bool find(int *arr,int target,int row,int col){
	bool found=false;
	int i=row-1,j=0;
	
	if(arr == NULL || row<=0 || col <=0){
		return false;
	}
	while(i >=0  && j<col){		//从左下角开始比较  也可以尝试从右上角比较 
		if(target==arr[i*col+j]){
			found=true;
			break;
		}
		else if(target>arr[i*col+j]){
			j++;
		}else{
			i--;
		}
	}
	return found;
}
int main(){
	
//	行数 = sizeof(array)/sizeof(array[0]);
//列数 = sizeof(array[0])/sizeof(array[0][0]);

	int arr[4][4]={1,2,8,9,
					2,4,9,12,
					4,7,10,13,
					6,8,11,15};
	int target;
	int row,col;
	bool found=false;
	printf("输入关键字target：");
	scanf("%d",&target);
	row=sizeof(arr)/sizeof(arr[0]);
	col=sizeof(arr[0])/sizeof(arr[0][0]);
	found=find(*arr,target,row,col);
	printf("%d\n",found);
	return 0;
} 


/*
题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
	 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。 
思路：选取左下角比较 
*/ 


