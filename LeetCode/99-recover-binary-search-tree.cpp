/**
 * 给你二叉搜索树的根节点 root ，该树中的两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树。
*/
#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
	// 先想想，两个节点被错误交换之后，搜索树有什么变化？
	// 对于中序结果来说，有效的二叉搜索树在中序遍历将得到递增值序列
	// 节点被错误交换后，将影响中序遍历的结果
    void recoverTree(TreeNode* root) {
		vector<TreeNode*> inorder_vec;
		inorder(root, inorder_vec);

		// 1, 7, 4, 5, 3	非相邻节点交换
		// 1, 4, 3, 5, 7	相邻节点交换

    }

	void inorder(TreeNode* root, vector<TreeNode*>& inorder_vec){
		stack<TreeNode*> stk;
		while (root || !stk.empty()){
			while (root){
				stk.push(root);
				root = root->left;
			}
			root = stk.top();
			stk.pop();
			inorder_vec.push_back(root);
			root = root->right;
		}
	}
};

int main(){
	return 0;
}