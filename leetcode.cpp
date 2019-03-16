#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
#include <sstream>
#include <queue>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};






class Solution {
public:
   	void dfs(TreeNode* root, int &depth, int &width, int d, int w, int &end)
   	{
   		if (root->left != NULL)
   		{
   			if (d + 1 > depth)
   			{
   				depth = d + 1;
   			}

   			dfs(root->left, depth, width, d+1, w);
   		}
   		else
   		{
   			if (depth > d)
   			{
   				end = 1;
   			}
   		}
   		if (end == 1)
   		{
   			return;
   		}
   		if (root->right != NULL)
   		{
   			if (w + 1 > width)
   			{
   				width = w + 1;
   			}
   			dfs(root->right, depth, width, d+1, w+1);
   		}
   		else
   		{
   			if (depth > d)
   			{
   				end = 1;
   			}
   		}
   		if (end == 1)
   		{
   			return;
   		}
   	}
    
    int countNodes(TreeNode* root) {
    	int depth = 1;
    	int width = 1;
    	int end = 0;
        dfs(root, 1, 1, 0, 0);
        
    }
};


int main()
{
	Solution s;
	int test[] = {1, 2, 3, 4, 5, 9};
	std::vector<int> test1(test, test+sizeof(test)/sizeof(int));

	s.searchRange(test1, 5);

	return 0;
}