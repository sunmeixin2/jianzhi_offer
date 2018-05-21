#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct Node{
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}*Bitree,BiNode;

typedef struct {
	Bitree data[MAXSIZE];
	int top;
}seqStack;

//�ÿ�ջ
seqStack *Init_stack(){
	seqStack *s;
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
void Push(seqStack *s,Bitree q){
	if(s->top == MAXSIZE -1){
		printf("ջ��");
		return ; 
	}
	else{
		s->top++;
		s->data[s->top]=q;
	}
	
} 

//��ջ

Bitree Pop(seqStack *s){
	Bitree q;
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

Bitree create(){
	Bitree root;
	char ch;
	ch=getchar();
	if(ch == '#'){
		return NULL;
	}
	else{
		root=(Bitree )malloc(sizeof(BiNode));
		root->data=ch;
		root->Lchild=create();
		root->Rchild=create();
	}
	return root;
}

//�ǵݹ��������
void  InOrder(Bitree root){
	Bitree p;
	seqStack *s;
	s=Init_stack();
	p=root;
	while(p!=NULL || !isEmpty(s)){
		while(p!=NULL){
			Push(s,p);
			p=p->Lchild;
		}
		if(!isEmpty(s)){
			p=Pop(s);
			printf("%c ",p->data);
			p=p->Rchild;
		}
	} 
} 

main(){
	Bitree root;
	root=create();
	InOrder(root);
}



 
