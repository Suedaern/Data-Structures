#include<stdio.h>
#include<stdlib.h>

//https://www.interviewbit.com/blog/level-order-traversal/

struct treeNode {
	int data;
	struct treeNode* leftptr;
	struct treeNode* rightptr;
};

struct treeNode* newNode(int data)
{
	//bos agaca ilk node'u ekliyo 
	struct treeNode* treeNode = (struct treeNode*)malloc(sizeof(struct treeNode));
	treeNode->data = data;
	treeNode->leftptr = NULL;
	treeNode->rightptr = NULL;

	return(treeNode);
}
int height(struct treeNode* root)
{
	if (root == NULL) //agacin bos olma durumu
		return 0;
	else
	{
		int lheight = height(root->leftptr);
		int rheight = height(root->rightptr);

		//agacin yuksekligini bulup donduruyo
		if (lheight > rheight)
			return(lheight + 1);
		else
			return(rheight + 1);
	}
}

void CurrentLevel(struct treeNode* root, int level)
{
	if (root == NULL) //agacin bos olma durumu 
		return;
	if (level == 1) //rootu yazýyo
		printf("%d\t", root->data);

	//leveli bir azaltip fonksiyonu en son rootu yazdirana kadar cagiriyo
	else if (level > 1)
	{
		CurrentLevel(root->leftptr, level - 1);
		CurrentLevel(root->rightptr, level - 1);
	}
}

void reverseLevelOrder(struct treeNode* root)
{
	//tersine ceviriyo
	int h = height(root);
	for (int i = h; i >= 1; i--)
	{
		CurrentLevel(root, i);
	}
}

int main()
{
	struct treeNode* root = newNode(9);
	root->leftptr = newNode(12);
	root->rightptr = newNode(21);
	root->leftptr->leftptr = newNode(15);
	root->leftptr->rightptr = newNode(8);
	root->rightptr->leftptr = newNode(7);
	root->rightptr->rightptr = newNode(11);

	printf("Level Order traversal of binary tree is \n");
	reverseLevelOrder(root);

}