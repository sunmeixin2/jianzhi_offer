#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
    	printf("%d ",pRoot->value);
        if(pRoot->Lchild != NULL){
        	PrintTree(pRoot->Lchild);
		}
        if(pRoot->Rchild != NULL){
        	PrintTree(pRoot->Rchild);
		}    	
    }
}
bool DoseTree1HaveTree2(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2){
	if(pRoot2==NULL){		//即子树已经遍历完 
		return true;
	}
	if(pRoot1==NULL){
		return false;
	}
	if(pRoot1->value != pRoot2->value){
		return false;
	}
	return DoseTree1HaveTree2(pRoot1->Lchild,pRoot2->Lchild) && DoseTree1HaveTree2(pRoot1->Rchild,pRoot2->Rchild);
}
bool HasSubtree(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2){
	bool result=false;
	if(pRoot1!=NULL && pRoot2!=NULL){
		if(pRoot1->value == pRoot2->value){
			result=DoseTree1HaveTree2(pRoot1,pRoot2); 
		}
		if(!result){
			result=HasSubtree(pRoot1->Lchild,pRoot2);
		}
		if(!result){
			result=HasSubtree(pRoot1->Rchild,pRoot2);
		}
	}
	return result;
}


// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        8       7                8
//     9     2          ----->  9     2
//        4     7  
int main(){
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode8_1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode7_1 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
 
	BinaryTreeNode* pNode8_2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode9_2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode2_2 = CreateBinaryTreeNode(3);
	
    ConnectTreeNodes(pNode8, pNode8_1, pNode7);
    ConnectTreeNodes(pNode8_1 , pNode9, pNode2);
    ConnectTreeNodes(pNode2, pNode4, pNode7_1);
    
    ConnectTreeNodes(pNode8_2 , pNode9_2, pNode2_2);
	bool result=HasSubtree(pNode8,pNode8_2);
	printf("%d",result);
//    PrintTree(pNode8);
//    printf("\n");
//    PrintTree(pNode8_2);
	return 0;
	
}
