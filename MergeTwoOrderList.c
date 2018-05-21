
/*
	��Ŀ�����������������������������������ϳɺ������
			��Ȼ������Ҫ�ϳɺ���������㵥���������� 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int val;
	struct Node *next;
}*list,listNode;
void print(list head){		//��ӡ���� 
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
//list Merge(list head1,list head2){		//�ݹ� 
//	if(head1==NULL){
//		return head2;
//	}
//	if(head2==NULL){
//		return head1;
//	}
//	list pMergeHead=NULL;
//	if(head1->val<head2->val){
//		pMergeHead=head1;
//		pMergeHead->next=Merge(head1->next,head2);
//	}else{
//		pMergeHead=head2;
//		pMergeHead->next=Merge(head1,head2->next);
//	}
//	return pMergeHead;
//}
list Merge(list head1,list head2){		//�ǵݹ� 
	if(head1==NULL){
		return head2;
	}
	if(head2==NULL){
		return head1;
	}
	list pMergeHead=NULL,p;
	
	if(head1->val < head2->val){		//ȷ��ͷָ�� 
		pMergeHead=head1;
		head1=head1->next; 
	}else{
		pMergeHead=head2;
		head2=head2->next; 
	}
	
	p=pMergeHead;
	while(head1!=NULL && head2!=NULL){
		if(head1->val < head2->val){
			p->next=head1;
			head1=head1->next;
		}else{
			p->next=head2;
			head2=head2->next;			
		}
		p=p->next;
	}
	if(head1!=NULL){
		p->next=head1;
	}
	if(head2!=NULL){
		p->next=head2;
	}
	return pMergeHead;
} 
int main(){
	int nums1[]={1,3,5,7};
	int nums2[]={2,4,6,8};
	list head1,head2,head;
	int len=sizeof(nums2)/sizeof(int);
	head1=create(nums1,len);
	head2=create(nums2,len);
	head=Merge(head1,head2); 
	
	print(head); 
	return 0;
} 
/*
	˼·�����õݹ��˼�룬��Ҫ���ǵ�һ������յ�����ͻ�����յ�ָ�룬���Ҫ�Կ�����������
			��һ�������ǿ�����Ҳ��������ͷ�����һ����ָ��ʱ��������Ҫ�����͵ڶ�������ϲ���
			��Ȼ�ϲ��Ľ�����ǵڶ�������ͬ��ڶ������� 
*/ 
