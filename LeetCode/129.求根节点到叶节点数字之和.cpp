/**
 * 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。

叶节点 是指没有子节点的节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers
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

class Solution {
public:
    int sumNumbers(TreeNode* root) {
		int sum = 0;
		sumNumbers(root, 0, sum);
		return sum;
    }

	void sumNumbers(TreeNode* root, int x, int& sum){
		if (!root){
			return;
		}
		x = 10 * x + root->val;
		// 遍历到叶子节点才加上
		if (!root->left && !root->right){
			sum += x;
			return;
		}
		sumNumbers(root->left, x, sum);
		sumNumbers(root->right, x, sum);
	}
};