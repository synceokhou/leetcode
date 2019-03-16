#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#ifndef MAX
#define MAX 100001
#endif

struct TreeNode
{
	char data;
	TreeNode *leftChild;
	TreeNode *rightChild;
	TreeNode(char d, TreeNode *l = NULL, TreeNode *r = NULL)
	{
		data = d;
		leftChild = l;
		rightChild = r;
	}
};


class BinaryTree
{

private:
	TreeNode *root;
public:
	BinaryTree()
	{
		root = NULL;
	}

	BinaryTree(char str[], int len)
	{
		root = NULL;
		int pos = 0;
		buildTree(root, str, pos);
	}

	void buildTree(TreeNode* &root, char str[], int &pos)
	{
		// printf("str[%d]: %c\n", pos, str[pos]);
		if (root == NULL && str[pos] != '#')
		{
			root = new TreeNode(str[pos++]);
			// printf("enter leftChild\n");
			buildTree(root->leftChild, str, pos);
			// printf("enter rightChild\n");
			buildTree(root->rightChild, str, pos);
		}
		else if (root == NULL && str[pos] == '#')
		{
			root = new TreeNode(str[pos++]);
		}
		// printf("leave\n");
	}

	~BinaryTree()
	{
		deleteNode(root);
	}

	void deleteNode(TreeNode* &root)
	{
		if (root->leftChild)
		{
			deleteNode(root->leftChild);
		}
		if (root->leftChild)
		{
			deleteNode(root->rightChild);
		}
		delete root;
		root = NULL;
	}
	
	void printTree()
	{
		LDR(root);
		printf("\n");
	}

	void LDR(TreeNode *root)
	{
		if (root->leftChild)
		{
			LDR(root->leftChild);
		}
		if (root->data != '#')
		{
			printf("%c ", root->data);
		}
		if (root->leftChild)
		{
			LDR(root->rightChild);
		}
	}

};








int main()
{
	char str[105];

	

	while(scanf("%s", str) != EOF)
	{
		int len = strlen(str);
		BinaryTree t(str, len);
		t.printTree();
	}


	return 0;
}















