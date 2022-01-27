/**
 * 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <algorithm>
#include <climits>

using namespace std;

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
	int maxPathSum(TreeNode *root)
	{
		if (!root){
			return 0;
		}
		int maxSum = INT_MIN;
		oneSideMax(root, maxSum);
		return maxSum;
	}

	int oneSideMax(TreeNode* root, int& maxSum){
		if (!root){
			return 0;
		}
		int leftMax = max(0, oneSideMax(root->left, maxSum));
		int rightMax = max(0, oneSideMax(root->right, maxSum));
		maxSum = max(leftMax + rightMax + root->val, maxSum);
		return max(leftMax, rightMax) + root->val;
	}
};