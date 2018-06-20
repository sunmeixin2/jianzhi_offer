/*
	题目：给定一棵二叉搜索树，请找出其中的第k大的结点。
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int value;
	struct Node *Lchild;
	struct Node *Rchild;
}BinaryTreeNode;
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode =(BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    pNode->value = value;
    pNode->Lchild = NULL;
    pNode->Rchild = NULL;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != NULL)
    {
        pParent->Lchild = pLeft;
        pParent->Rchild = pRight;
    }
}
void PrintTree(BinaryTreeNode* pRoot)		//前序遍历     可以变换遍历方式，只要改变 printf（）函数的位置  
{
    if(pRoot != NULL)
    {
    	
        if(pRoot->Lchild != NULL){
        	PrintTree(pRoot->Lchild);
		}
		printf("%d ",pRoot->value);
        if(pRoot->Rchild != NULL){
        	PrintTree(pRoot->Rchild);
		}    	
    }
}
BinaryTreeNode* KthNodeCore(BinaryTreeNode *pRoot,unsigned int *k){
	BinaryTreeNode *target=NULL;

	if(pRoot ->Lchild !=NULL)
		target=KthNodeCore(pRoot->Lchild,k);

	if(target == NULL){	
		if(*k == 1)
			target = pRoot;
		(*k)--;
	}
	if(target == NULL && pRoot->Rchild != NULL )
		target = KthNodeCore(pRoot->Rchild,k);

	return target;
	
}

BinaryTreeNode* KthNode(BinaryTreeNode* pRoot,unsigned int k){
	if(pRoot == NULL || k == 0)
		return NULL;
	return KthNodeCore(pRoot,&k);
}

//            8
//        6      10
//      5  7   9   11
int main(){
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    // PrintTree(pNode8);		//打印二叉树
    int k;
    printf("input k:");
    scanf("%d",&k);
    BinaryTreeNode* result=KthNode(pNode8,k);
    printf("%d\n", result->value);
	return 0;
	
}


/*
	题解：　利用中序遍历
*/