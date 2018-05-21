#include<stdlib.h>
#include<stdio.h>
#include<string.h> 
typedef struct ListTable{
	int id;
	struct ListTable *next;
}list;
void printList(list *p){		//从尾到头打印 

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
	for(i=1;i<=5;i++){		//创建链表 
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
	//顺序打印 
	p1=head;
	while(p1!=NULL){
		printf("%d\t",p1->id);
		p1=p1->next;
	}
} 

/*
题目描述：	输入一个链表，从尾到头打印链表每个节点的值
思路：	可利用栈或递归实现（递归的本质也是使用堆栈结构） 
*/ 
