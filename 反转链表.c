/*
	题目：输入一个链表，反转链表后，输出链表的所有元素。 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int val;
	struct Node *next;
}*list,listNode;
void print(list head){
	list p1=head;

	while(p1){
		printf("%d ",p1->val);
		p1=p1->next; 
	} 
}
list create(int *nums,int len){
	list head,p1,p2;
	int i;
	p1=p2=(list)malloc(sizeof(listNode));
	head=p1;
	p1->next=NULL;
	for(i=0;i<len;i++){
		p1->val=nums[i];
		p1->next=NULL;
		p2->next=p1;
		p2=p1;
		p1=(list)malloc(sizeof(listNode));
	}
	free(p1);
	p2->next=NULL;
	return head;
}
list ReverseList(list head){
	list pPrev,pNode,pNext,headNew=NULL;
	pNode=head;
	pPrev=NULL;
	while(pNode){
		pNext=pNode->next;
		if(pNext==NULL){		//此时当前节点pNode是最后一个节点了 
			headNew=pNode;		 
		}
		pNode->next=pPrev;
		
		pPrev=pNode;
		pNode=pNext;
	}
	return headNew;
}
int main(){
	
	int nums[]={1,2,3,4,5,6,7};
	list head;
	
	int len=sizeof(nums)/sizeof(int);
	head=create(nums,len);
	head=ReverseList(head);
	print(head); 
	return 0;
} 

/*
	思路：定义3个指针，分别是pPrev（前一个节点）、 pNode（当前遍历的节点）、 pNext（后一个节点） 
*/
 
