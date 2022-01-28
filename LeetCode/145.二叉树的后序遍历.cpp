/**
 * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
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
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> stk;
		TreeNode* prev = nullptr;
		while (root && !stk.empty()){
			while (root != nullptr){
				stk.push(root);
				root = root->left;
			}
			root = stk.top();
			if (!root->right || root->right == prev){
				ret.emplace_back(root->val);
				prev = root;
				root = nullptr;
				stk.pop();
			}else{
				root = root->right;
			}
		}
		return ret;
    }
};