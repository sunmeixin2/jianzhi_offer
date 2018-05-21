#include<stdio.h>
#include<stdlib.h>

typedef struct work{
	int d,p;
}wk;
typedef struct people{
	int a,index,money;
}pl;


//int 
int cmp1 ( const void *a , const void *b )
{
	return *(int *)a - *(int *)b;
}

//double
int cmp2(const void *a ,const void * b)
{

 return (*(double *)a > *(double * )b ? 1 : -1);

}

//struct 
int cmp3( const void *a , const void *b )
{
	return (*(wk *)a).d > (*(wk *)b).d ? 1 : -1;
}
int cmp4( const void *a , const void *b )
{
	return (*(pl *)a).a > (*(pl *)b).a ? 1 : -1;
}
int main(){
	int i;
	int num[5]={2,3,6,5,4};
	double arr[5]={2.0,3.2,6.0,5.3,4.6};
	
	wk w[10];
	pl p[10];
	
	//int 
	qsort(num,5,sizeof(num[0]),cmp1);
	
	//struct
	qsort(w,10,sizeof(w[0]),cmp3);
	qsort(p,10,sizeof(p[0]),cmp4);
	
	 
	
//	for(i=0;i<5;i++){
//		printf("%d ",num[i]);
//	}
//	
//	printf("\n");
//	
//	qsort(arr,5,sizeof(arr[0]),cmp2);
//	for(i=0;i<5;i++){
//		printf("%f ",arr[i]);
//	}
	return 0;
}
