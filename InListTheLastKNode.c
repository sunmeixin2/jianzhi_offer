/*
	题目: 输入一个链表，输出该链表中倒数第k个结点。 
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
void FindKthToTail(list head,int k){
	list p1,p2;
	p1=p2=head;

	while(p1){

		p1=p1->next;
		if(k<1){
			p2=p2->next;
		}
		k--;
	}
	printf("%d ",p2->val);
	
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
int main() {
	int k;
	scanf("%d",&k);
	
	int nums[]={1,2,3,4,5,6,7};
	list head;
	int len=sizeof(nums)/sizeof(int);
	head=create(nums,len);
	FindKthToTail(head,k);
	return 0;
} 

/*
	思路： 由于是单向链表，所以肯定不能从链表的尾部向前遍历，所以只能考虑从链表的头部遍历
			如果只遍历一遍链表的话，同时也不知道链表的长度，所以没办法求出n-k+1,
			因此  设置两个指针，先让第一个指针从链表的头部开始遍历向前走k-1步，第二个指针不动
			从第K步开始，第二个指针从头部向前遍历，由于两个指针保持K-1，当第一个指针到达链表的尾节点时，
			第二个指针正好指向倒数第K个节点
			 
*/
