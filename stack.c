#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct {
	int data[MAX]; 
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
int Push(seqStack *s,int q){
	if(s->top == MAX-1)
		return 0;
	else{
		s->top++;
		s->data[s->top]= q; 
	}
	return 1;
} 
//��ջ
int Pop(seqStack *s){
 	int q;
 	if(isEmpty(s)){
 		printf("ջ��\n");
 		return ;
	 }
	else{
 		q=s->data[s->top];
 		s->top--;
 	}
 	return q;
}
int main(){
	
	seqStack *stack;
	stack=Init_stack(stack);
	
	return 0;
}
