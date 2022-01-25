/**
 * 给你二叉搜索树的根节点 root ，该树中的两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树。
*/
#include<iostream>
#include<stack>
#include<vector>
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
		vector<TreeNode*> vec;
		inorder(root, vec);

		// 1, 7, 4, 5, 3	非相邻节点交换
		// 1, 4, 3, 5, 7	相邻节点交换

		vector<TreeNode*> error_vec;
		for (int i = 1; i < vec.size(); i++){
			if (vec[i]->val < vec[i - 1]->val){
				if (error_vec.empty()){
					error_vec.push_back(vec[i - 1]);
				}else{
					error_vec.push_back(vec[i]);
				}
				if (error_vec.size() > 1){
					break;
				}
			}
		}
		if (error_vec.size() == 1){
			vector<TreeNode*>::iterator it = find(vec.begin(), vec.end(), error_vec[0]);
			it++;
			error_vec.push_back(*it);
		}
		swap(error_vec[0]->val, error_vec[1]->val);
    }

	void inorder(TreeNode* root, vector<TreeNode*>& vec){
		stack<TreeNode*> stk;
		while (root || !stk.empty()){
			while (root){
				stk.push(root);
				root = root->left;
			}
			root = stk.top();
			stk.pop();
			vec.push_back(root);
			root = root->right;
		}
	}


	// 上面的解法要先遍历完整个树才能找出所有顺序不符合要求的
	void recoverTree(TreeNode* root){
		TreeNode* pre;
		TreeNode* x, y;

		stack<TreeNode*> stk;
		while (root || !stk.empty()){
			while (root){
				stk.push(root);
				root = root->left;
			}
			root = stk.top();
			stk.top();

			if (pre || root->val < pre->val){
				y = root;
				if (x == nullptr){
					x = pre;
				}
			}
			pre = root;
			root = root->right;
		}
		swap(x->val, y->val);
	}
};

int main(){
	return 0;
}