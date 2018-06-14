/*
	 题目：输入两个链表，找出它们的第一个公共结点。
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
	int val;
	struct Node *next;
}*list,ListNode;
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
	p1=p2=(list)malloc(sizeof(ListNode));
	head=p1;
	p1->next=NULL;
	for(i=0;i<len;i++){
		p1->val=nums[i];
		p1->next=NULL;
		p2->next=p1;
		p2=p1;
		p1=(list)malloc(sizeof(ListNode));
	}
	free(p1);
	p2->next=NULL;
	return head;
}
unsigned int GetListLength(ListNode *phead){

	unsigned int len=0;
	ListNode *pNode=phead;
	while(pNode != NULL){
		++len;
		pNode=pNode->next;
	}

	return len;
}

ListNode* FindFirstCommonNode(ListNode *phead1,ListNode *phead2){
	//printf("%d\n", phead1->val);
	unsigned int len1=GetListLength(phead1);
	unsigned int len2=GetListLength(phead2);
	int nLengthDif=len1 - len2;
	
	ListNode *pListHeadLong=phead1;
	ListNode *pListHeadShort=phead2;

	if(len2 > len1){
		pListHeadLong=phead2;
		pListHeadShort=phead1;
		nLengthDif=len2 - len1;
	}

	//先在链表上走几步，在同时在两个链表上遍历
	for(int i=0;i<nLengthDif;++i)
		pListHeadLong=pListHeadLong->next;


	while((pListHeadLong != NULL) && (pListHeadShort != NULL) && (pListHeadLong->val != pListHeadShort->val)){
		
		pListHeadShort=pListHeadShort->next;
		pListHeadLong=pListHeadLong->next;
	}

	//得到第一个公共节点
	ListNode *pFirstCommonNode=pListHeadLong;

	return pFirstCommonNode;
}
int main(){
	int data1[]={1,2,3,6,7};
	int data2[]={4,5,6,7};
	int len1=sizeof(data1)/sizeof(int);
	int len2=sizeof(data2)/sizeof(int);
	list phead1 =create(data1,len1);
	list phead2 =create(data2,len2);

	list pNode=FindFirstCommonNode(phead1,phead2);
	printf("%d\n",pNode->val);
}

/*
	题解：方法一，借用栈，可以从尾到头遍历出链表，找到最后一个相同的节点
		方法二（推荐）：　先遍历每个链表记录每个链表的长度分别是Ｍ和Ｎ，lenDif=M-N,较长的链表先走lenDif长个节点，
			最后两个链表一起遍历找到第一个相同的节点就是我们要找的第一个公共节点。
*/