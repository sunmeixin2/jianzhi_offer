#include<stdlib.h>
#include<stdio.h>
#include<string.h> 
typedef struct ListTable{
	int id;
	struct ListTable *next;
}list;
void printList(list *p){		//��β��ͷ��ӡ 

	if(p->next!=NULL){
		printList(p->next);
	}
	printf("%d\t",p->id);

}

main(){
	list *head,*p1,*p2;
	int i;
	p1=p2=(list *)malloc(sizeof(list));
	head=p1;
	p1->next=NULL;
	p2=p1;
	for(i=1;i<=5;i++){		//�������� 
		scanf("%d",&p1->id);
		p1->next=NULL;
		p2->next=p1;
		p2=p1;
		p1=(list *)malloc(sizeof(list));
		
	}
	free(p1);
	p2->next=NULL;
	printList(head);
	
	printf("\n");
	//˳���ӡ 
	p1=head;
	while(p1!=NULL){
		printf("%d\t",p1->id);
		p1=p1->next;
	}
} 

/*
��Ŀ������	����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ
˼·��	������ջ��ݹ�ʵ�֣��ݹ�ı���Ҳ��ʹ�ö�ջ�ṹ�� 
*/ 
