#include<stdio.h>
void PrintMatrixInCircle(int (*number)[4],int cols,int rows,int start){
	int end_x=cols-1-start;
	int end_y=rows-1-start;
	
	//从左到右打印一行
	for(int i=start;i<=end_x;i++){
		printf("%d ",number[start][i]);
	}

	//从上到下打印一列
	if(start < end_y){
		for(int i=start+1;i<=end_y;i++)
			printf("%d ",number[i][end_x]);
	}
	
	//从右到左打印一行
	if(start < end_x && start < end_y){
		for(int i=end_x-1;i>=start;--i)
			printf("%d ",number[end_y][i]);
	}

	//从下到上打印一列
	if(start < end_x && start < end_y-1){
		for(int i=end_y-1;i>=start+1;--i)
			printf("%d ",number[i][start]);

	}
	
}
void PrintMatrixClockwisely(int (*number)[4],int cols,int rows){

	if(number==NULL || cols<=0 || rows<=0)
		return ;
	int start=0;
	
	while(cols > start*2 && rows > start*2 ){
		PrintMatrixInCircle(number,cols,rows,start);
		start++;
	}
}
int main(){
	int number[4][4]={ 1,2,3,4,5,
					  6,7,8,9,10,
					  11,12,13,14,15,
					  16};
	PrintMatrixClockwisely(number,4,4);
	printf("\n");
	return 0;
}
