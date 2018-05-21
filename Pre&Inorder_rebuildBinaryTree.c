#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	int data;
	struct Node *Lchild;
	struct Node *Rchild;	
}list;

list *create(char *front,char *center,int len){
	list *root;
	char ch;
	int i,index;
	if(len<=0){
		return NULL;
	}
	ch=front[0];
	for(i=0;i<len;i++){
		if(center[i]==ch){
			index=i;
		}
	}
	root=(list *)malloc(sizeof(list));
	root->data=ch;
//	printf("%c\n",root->data);
//	exit(0);
	root->Lchild=create(front+1,center,index);
	root->Rchild=create(front+index+1,center+index+1,len-index-1);
	return root;
}
void PostOrder(list *root){		//ºóÐò±éÀú 
	if(root){
		PostOrder(root->Lchild);
		PostOrder(root->Rchild);
		printf("%c",root->data);
	}
}
main(){
//	char first[20]="12473568",middle[20]="47215386";
//char first[20]="12345",middle[20]="54321";
//char first[20]="12345",middle[20]="12345";
char first[20]="1245367",middle[20]="4251637";
	int len;
	list *root;
	len=strlen(middle);
	root=create(first,middle,len);
	PostOrder(root);
}
