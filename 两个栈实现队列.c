#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct {
	int data[MAX]; 
	int top;
}seqStack;

//  ÖÃ¿ÕÕ» 
seqStack *Init_stack(seqStack *s){
	s=malloc(sizeof(seqStack));
	s->top=-1;
	return s;
}

//ÅÐÕ»¿Õ
int isEmpty(seqStack *s){
	if(s->top == -1)
		return 1;
	else
		return 0;
} 

//ÈëÕ»
int Push(seqStack *s,int q){
	if(s->top == MAX-1)
		return 0;
	else{
		s->top++;
		s->data[s->top]= q; 
	}
	return 1;
} 
 

//³öÕ»
int Pop(seqStack *s){
 	int q;
 	if(isEmpty(s)){
 		printf("Õ»¿Õ\n");
 		return ;
	 }
	else{
 		q=s->data[s->top];
 		s->top--;
 	}
 	return q;
}
void stack_push(seqStack *stack1,int x){		
	Push(stack1,x);
}
void stack_pop(seqStack *stack1,seqStack *stack2){
	int x;
	if(isEmpty(stack2)){
		while(!isEmpty(stack1)){
			x=Pop(stack1);
			Push(stack2,x);
		}
	}
}

int main(){
	int i;
	
	seqStack *stack1,*stack2;
	
	stack1=Init_stack(stack1);
	stack2=Init_stack(stack2);
	
	int arr[5]={1,2,3,4,5};
	
	for(i=0;i<5;i++){
		stack_push(stack1,arr[i]);
	}
	stack_pop(stack1,stack2);
	
	while(!isEmpty(stack2)){
		printf("%d ",Pop(stack2));
	}
	return 0;
}
