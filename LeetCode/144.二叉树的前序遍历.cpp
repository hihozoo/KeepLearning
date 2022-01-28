/**
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
*/

#include <algorithm>
#include <climits>
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
    vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		preorder(root, ret);
		return ret;
    }

	// 整体思路就是模拟函数栈过程
	vector<int> preorderTraversal2(TreeNode* root){
		vector<int> ret;
		stack<TreeNode*> stk;

		while (root || !stk.empty()){
			if (!root){
				root = stk.top();
				root = root->right;
				stk.pop();
			}
			if (!root){
				continue;
			}
			stk.push(root);
			ret.push_back(root->val);
			root = root->left;
		}
		return ret;
	}

	void preorder(TreeNode* root, vector<int>& ret){
		if (!root){
			return;
		}
		ret.push_back(root->val);
		preorder(root->left, ret);
		preorder(root->right, ret);
	}
};