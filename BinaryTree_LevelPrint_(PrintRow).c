#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct Node{
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}BiTNode,*BiTree;
typedef struct{
	BiTree data[MAXSIZE];
	int front,rear;
}SeqQueue;
SeqQueue *Init_Queue(SeqQueue *q){		//初始化队列 
	q=malloc(sizeof(SeqQueue));
	q->front=q->rear=-1;
	return q;
}
void EntryQueue(SeqQueue *q,BiTree t){		//入队 
	q->rear=(q->rear+1)%MAXSIZE;
	q->data[q->rear]=t;
}

BiTree OutQueue(SeqQueue *q,BiTree t){		//出队 
	q->front=(q->front+1)%MAXSIZE;
	t=q->data[q->front];
	return t;
}

int EmptyQueue(SeqQueue *q){		//判队空 
	if(q->front == q->rear)
		return 1;
	else
		return 0;
}

BiTree create(){		//创建二叉树 
	BiTree root;
	char ch;
	ch=getchar();
	if(ch == '#'){
		return NULL;
	}else{
		root=(BiTree )malloc(sizeof(BiTNode));
		root->data=ch;
		root->Lchild=create();
		root->Rchild=create();
	}
	return root;
} 
void LevelOrder(BiTree root){			//按层遍历 
	SeqQueue *q,*s; 
	BiTree t,last,nlast;		//last表示正在打印的当前行的最右节点  nlast表示下一行的最右节点 
	q=Init_Queue(q);
	t=root;
	EntryQueue(q,t);
	last=t;
	while(!EmptyQueue(q)){
		t=OutQueue(q,t);
		printf("%c",t->data);
		
		if(t->Lchild!=NULL){
			EntryQueue(q,t->Lchild);
			nlast=t->Lchild;
		}
		if(t->Rchild!=NULL){
			EntryQueue(q,t->Rchild);
			nlast=t->Rchild;
		}
		if(last==t){		//当正在遍历的节点等于当前行的最右节点时  换行 
			printf("\n");
			last=nlast;
		}
	}

}
main(){
	BiTree root;
	root=create();
	LevelOrder(root);
}









