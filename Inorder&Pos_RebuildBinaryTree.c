#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
	int data;
	struct Node *Lchild;
	struct Node *Rchild;
}list;
list *create(char *center,char *back,int len);
void PreOrder(list *root);
main(){
	list *root;
	char center[20]="47215386",back[20]="74258631";
	int len;
	len=strlen(center);
	root=create(center,back,len);
	PreOrder(root);
	
}

list *create(char *center,char *back,int len){
	list *root;
	int i,index;
	char ch;
	if(len<=0){
		return NULL;
	}
	ch=back[len-1];
	for(i=0;i<len;i++){
		if(ch==center[i]){
			index=i;
		}
	}
	root=(list *)malloc(sizeof(list));
	root->data=ch;			
	
	root->Lchild=create(center,back,index);
	root->Rchild=create(center+index+1,back+index,len-index-1);
	return root;
}
void PreOrder(list *root){
	if(root!=NULL){
		printf("%c",root->data);
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
}
