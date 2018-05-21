/*
	��Ŀ�� ���������Ķ�����������任ΪԴ�������ľ��� 
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int value;
	struct Node *Lchild;
	struct Node *Rchild;
}BinaryTreeNode;
BinaryTreeNode* CreateBinaryTreeNode(int value)		//�����ڵ� 
{
    BinaryTreeNode* pNode =(BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    pNode->value = value;
    pNode->Lchild = NULL;
    pNode->Rchild = NULL;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)		//���ӵ�ǰ�ڵ������ֱ�ӵ� 
{
    if(pParent != NULL)
    {
        pParent->Lchild = pLeft;
        pParent->Rchild = pRight;
    }
}
void PrintTree(BinaryTreeNode* pRoot)		//ǰ�����     ���Ա任������ʽ��ֻҪ�ı� printf����������λ�� 
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

void MirrorRecursively(BinaryTreeNode *pNode){		//����������ת��    
	if(pNode==NULL)
		return ;
	if(pNode->Lchild == NULL && pNode->Rchild == NULL)		//�����Ҷ�ӽڵ�  ��ֱ�ӷ��� 
		return ;
		
	//���������ӽڵ� 
	BinaryTreeNode *pTemp=pNode->Lchild;		 
	pNode->Lchild=pNode->Rchild;
	pNode->Rchild=pTemp;
	
	if(pNode->Lchild)		//������������ 
		MirrorRecursively(pNode->Lchild);
	if(pNode->Rchild)		//������������ 
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
	˼·�������������;�����������Է������ǵĸ��ڵ���ͬ�������ǵ����������ӽڵ㽻����λ�á�
			��ǰ������������ÿ���ڵ㣬����������Ľڵ����ӽڵ㣬�ͽ������������ӽڵ㡣
			�����������з�Ҷ�ڵ�������ӽڵ�֮�󣬾͵õ�����ľ��� 
*/ 
