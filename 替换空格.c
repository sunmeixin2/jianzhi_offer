#include<stdio.h>
#include<string.h>
void replaceSpace(char *str){
	
	if(str == NULL || strlen(str)<=0){
		return;
	}
	int indexold,indexnew,newlen,count=0;	//countΪ����ո���
	int i;
	for(i=0;i<strlen(str);i++){
		if(str[i]==' ')
			++count;
	}
	indexold=strlen(str)-1;		//indexoldΪ�滻ǰ��str�±�
	newlen=strlen(str)+count*2;	//����ո�ת����%20֮���str����
	indexnew=newlen-1;	//indexnewΪΪ�ѿո��滻Ϊ%20���str�±�

	for(;indexold>=0 ;indexold--){
		if(str[indexold]==' '){
			str[indexnew--]='0';
			str[indexnew--]='2';
			str[indexnew--]='%';
		}else{
			str[indexnew--]=str[indexold];
		}
	}
}
main(){
	int i;
	//�������� 
	char str[30]="we are happy";
//	char str[30]=" helloworld";	//�ո��ھ��ӿ�ͷ 
//	char str[30]="helloworld ";//�ո��ھ��ӽ�β 
//	char str[30]="hello  world";	//�����������ո� 
//	char str[30]="";	//�մ� 


	replaceSpace(str);
//	replaceSpace(NULL);	//����NULL 
	printf("%s",str);
	
}


/*
��Ŀ����һ���ַ����еĿո��滻�ɡ�%20����
	 ���磬���ַ���ΪWe Are Happy.
	 �򾭹��滻֮����ַ���Ϊ  We%20Are%20Happy�� 
˼·��  ����1���滻�ַ���������ԭ�����ַ��������滻�������¿���һ���ַ������滻��
		����2���ڵ�ǰ�ַ����滻����ô�滻�Ÿ���Ч�ʣ�������java�����е�replace��������
      	��ǰ�����滻��������ַ�Ҫ���������ƶ���Ҫ����ƶ�������Ч�ʵ���
      	�Ӻ���ǰ���ȼ�����Ҫ���ٿռ䣬Ȼ��Ӻ���ǰ�ƶ�����ÿ���ַ�ֻΪ�ƶ�һ�Σ�����Ч�ʸ���һ�㡣 
*/



