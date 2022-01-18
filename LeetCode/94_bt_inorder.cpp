#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};

class Solution {
public:
	// 中序遍历, 模拟函数的进栈出栈过程
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> stk;
		while (root || !stk.empty()){
			while (root){
				stk.push(root);
				root = root->left;
			}
			root = stk.top();
			stk.pop();
			ret.push_back(root->val);
			root = root->right;
		}
		return ret;
    }
};

int main(){
	TreeNode* root = new TreeNode(1);

	TreeNode* temp = root;
	temp->right = new TreeNode(2);
	temp = temp->right;

	temp->left = new TreeNode(3);

	Solution s = Solution();
	for (int v: s.inorderTraversal(root)){
		cout << v << endl;
	}

	return 0;
}