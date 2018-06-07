/*
	题目：在一个mxn的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于0）。
		你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一个，直到到达棋盘的右下角。
		给定一个棋盘及其上面的礼物，请计算你最多能拿到多少价值的礼物？

		1    10   3    8
		12   2    9    6
		5    7    4    11
		3    7    16   5

		礼物的最大价值为1+12+5+7+7+16+5=53
*/

#include<stdio.h>
#include<string.h>
int max(int x,int y){
	return x >= y ? x : y ;
}
int getMaxValue_solution(int *values,int rows,int cols){

	if(values==NULL || rows <= 0 || cols <= 0)
		return 0;

	int maxValues[cols];
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){

			int left=0;
			int up=0;

			if(i>0)
				up=maxValues[j];  //f(i-1,j)   maxValues[i-1][j];
			if(j>0)
				left=maxValues[j-1];		//f(i,j-1)  maxValues[i][j-1]

			maxValues[j]=max(left,up)+values[i*cols+j];

		}
	}
	int max_Value=maxValues[cols-1];

	return max_Value;
}
int main(){

	int values[4][4]={
		1,10,3,8,
		12,2,9,6,
		5,7,4,11,
		3,7,16,5
	};
	int rows=sizeof(values)/sizeof(values[0]);
	int cols=sizeof(values[0])/sizeof(values[0][0]);
	int result=getMaxValue_solution(*values,rows,cols);
	printf("%d\n", result);
	return 0;
}

/** 
	思路：典型的可以用动态规划解决的问题
			定义ｆ(i,j)表示到达坐标位(i,j)的格子时能拿到的礼物总和的最大值。有两种可能的途径到达坐标位(i,j)的格子，
			通过（i-1,j)或者(i,j-1),所以f(i,j)=max(f(i-1,j),f(i,j-1))+gift[i,j]。
			基于循环的效率比递归要高很多。

			定义一个一维数组来代替二维矩阵maxValues(也可以用二维矩阵)，数组长度为棋盘列数cols
*/