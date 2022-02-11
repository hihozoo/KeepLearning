/**
 * 给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。
*/

#include <climits>
#include <queue>

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
	// 动态规划思路
	// 1) 有重叠子问题，最小深度 == 1 + 最小的左右子树
	// 2) 最优子结构，可以通过求子问题的最优解，来求解原问题的最优解
	// 3) 状态转移方程 f(n) = min(f(n->left), f(n->right)) + 1
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

	// BFS 的思路
	// 也就是层序遍历
	// 遍历一层的时候，顺便节点的子节点加入到下一轮需要遍历的队列中
	// 空间复杂度为 O(n/2)
	int minDepth(TreeNode* root){
		if (!root){
			return 0;
		}
		queue<TreeNode*> que;
		que.push(root);

		int depth = 1;
		while (!que.empty()){
			int sz = que.size();
			while (sz-- > 0){
				TreeNode* root = que.front();
				que.pop();
				if (!root->left && !root->right){
					return depth;
				}
				if (root->left){
					que.push(root->left);
				}
				if (root->right){
					que.push(root->right);
				}
			}
			depth++;
		}
		return depth;
	}
};