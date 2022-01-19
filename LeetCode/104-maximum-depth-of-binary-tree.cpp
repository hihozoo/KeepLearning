/**
 * 给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
		if (!root){
			return 0;
		}
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return (left > right ? left: right) + 1;
    }
};
