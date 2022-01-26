/**
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
*/

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	bool isBalanced(TreeNode *root)
	{
		int height = 0;
		return isBalanced(root, height);
	}

	bool isBalanced(TreeNode* root, int& height){
		if (!root){
			return true;
		}
		int left = 0;
		int right = 0;
		if (!isBalanced(root->left, left)){
			return false;
		}
		if (!isBalanced(root->right, right)){
			return false;
		}
		height = max(left, right) + 1;
		return abs(left - right) <= 1;
	}
};