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
// ������ȫ������������Ҷ�ӽڵ㣬�����ڵ㶼�������ӽڵ�
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

    PrintTree(pNode8);
	return 0;
	
}
