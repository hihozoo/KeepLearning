/**
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
*/
#include <stack>
#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		if (root){
			que.push(root);
		}

		vector<vector<int> > vec;
		int cnt = 0;
		while (!que.empty()){
			cnt = que.size();
			vector<int> tmp;
			while (cnt-- > 0){
				TreeNode* node = que.front();
				tmp.push_back(node->val);

				que.pop();
				if (node->left){
					que.push(node->left);
				}
				if (node->right){
					que.push(node->right);
				}
			}
			vec.push_back(tmp);
		}
		return vec;
    }
};