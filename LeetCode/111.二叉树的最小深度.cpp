/**
 * 给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。
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
	int minDepth(TreeNode *root){
		if (!root){
			return 0;
		}
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		if ((left == 0 || right == 0) && left != right){
			return max(left, right) + 1;
		}
		return min(left, right) + 1;
	}
};