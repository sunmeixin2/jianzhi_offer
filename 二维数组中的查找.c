#include<stdio.h>
#include<stdbool.h>
bool find(int *arr,int target,int row,int col){
	bool found=false;
	int i=row-1,j=0;
	
	if(arr == NULL || row<=0 || col <=0){
		return false;
	}
	while(i >=0  && j<col){		//�����½ǿ�ʼ�Ƚ�  Ҳ���Գ��Դ����ϽǱȽ� 
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
	
//	���� = sizeof(array)/sizeof(array[0]);
//���� = sizeof(array[0])/sizeof(array[0][0]);

	int arr[4][4]={1,2,8,9,
					2,4,9,12,
					4,7,10,13,
					6,8,11,15};
	int target;
	int row,col;
	bool found=false;
	printf("����ؼ���target��");
	scanf("%d",&target);
	row=sizeof(arr)/sizeof(arr[0]);
	col=sizeof(arr[0])/sizeof(arr[0][0]);
	found=find(*arr,target,row,col);
	printf("%d\n",found);
	return 0;
} 


/*
��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
	 �����һ������������������һ����ά�����һ���������ж��������Ƿ��и������� 
˼·��ѡȡ���½ǱȽ� 
*/ 


