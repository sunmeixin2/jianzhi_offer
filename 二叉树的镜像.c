/*
	题目： 操作给定的二叉树，将其变换为源二叉树的镜像。 
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int value;
	struct Node *Lchild;
	struct Node *Rchild;
}BinaryTreeNode;
BinaryTreeNode* CreateBinaryTreeNode(int value)		//创建节点 
{
    BinaryTreeNode* pNode =(BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    pNode->value = value;
    pNode->Lchild = NULL;
    pNode->Rchild = NULL;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)		//连接当前节点的左右直接点 
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
    	printf("%d ",pRoot->value);
        if(pRoot->Lchild != NULL){
        	PrintTree(pRoot->Lchild);
		}
        if(pRoot->Rchild != NULL){
        	PrintTree(pRoot->Rchild);
		}    	
    }
}

void MirrorRecursively(BinaryTreeNode *pNode){		//二叉树镜像转换    
	if(pNode==NULL)
		return ;
	if(pNode->Lchild == NULL && pNode->Rchild == NULL)		//如果是叶子节点  则直接返回 
		return ;
		
	//交换左右子节点 
	BinaryTreeNode *pTemp=pNode->Lchild;		 
	pNode->Lchild=pNode->Rchild;
	pNode->Rchild=pTemp;
	
	if(pNode->Lchild)		//若左子树不空 
		MirrorRecursively(pNode->Lchild);
	if(pNode->Rchild)		//若右子数不空 
		MirrorRecursively(pNode->Rchild);
} 
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
    
	PrintTree(pNode8);
	MirrorRecursively(pNode8);
	printf("\n");
    PrintTree(pNode8);
	return 0;
} 

/*
	思路：分析二叉树和镜像二叉树可以发现他们的根节点相同，但他们的左右两个子节点交换了位置。
			先前序遍历这棵树的每个节点，如果遍历到的节点有子节点，就交换他的两个子节点。
			当交换完所有非叶节点的左、右子节点之后，就得到了书的镜像 
*/ 
