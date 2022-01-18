/**
 * 翻转二叉树
*/
#include <algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
		if (!root){
			return nullptr;
		}
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
    }
};