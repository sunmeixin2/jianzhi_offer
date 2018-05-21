#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
 
typedef struct Node{
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}*BiTree,BiNode;

typedef struct {
	BiTree data[MAXSIZE]; 
	int top;
}seqStack;

//  �ÿ�ջ 
seqStack *Init_stack(seqStack *s){
	s=malloc(sizeof(seqStack));
	s->top=-1;
	return s;
}

//��ջ��
int isEmpty(seqStack *s){
	if(s->top == -1)
		return 1;
	else
		return 0;
} 

//��ջ
int Push(seqStack *s,BiTree q){
	if(s->top == MAXSIZE-1)
		return 0;
	else{
		s->top++;
		s->data[s->top]= q; 
	}
	return 1;
} 
 

//��ջ
BiTree Pop(seqStack *s,BiTree q){
 	
 	if(isEmpty(s)){
 		printf("ջ��\n");
 		return NULL;
	 }
	else{
 		q=s->data[s->top];
 		s->top--;
 	}
 	return q;
}

//���������� 
BiTree create(){
	BiTree root;
	char ch;
	ch=getchar();
	if(ch== '#')
		return NULL;
	else{
		root=(BiTree )malloc(sizeof(BiNode));
		root->data=ch;
		root->Lchild=create();
		root->Rchild=create();
	}
	return root;
}



//����ǵݹ����������
void PreOrder(BiTree root){
	BiTree p;
	seqStack *s;
	s=Init_stack(s);
	p=root;
	while(p != NULL || !isEmpty(s)){
		while(p!=NULL){
			printf("%c\t",p->data);
			Push(s,p);
			p=p->Lchild;
		}
		if(!isEmpty(s)){
			p=Pop(s,p);
			p=p->Rchild;
		}
	} 
} 


main(){
	BiTree root;
	root=create();
	PreOrder(root);
}




















