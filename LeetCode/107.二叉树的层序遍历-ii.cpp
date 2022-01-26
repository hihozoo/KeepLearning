/**
 * 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
*/

#include <iostream>
#include <vector>
#include <deque>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (!root){
			return vector<vector<int>>();
		}
		deque<vector<int>> ret;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()){
			int size = que.size();
			vector<int> levelVec;
			while (size-- > 0){
				TreeNode* cur = que.front();
				que.pop();

				levelVec.push_back(cur->val);
				if (cur->left){
					que.push(cur->left);
				}
				if (cur->right){
					que.push(cur->right);
				}
			}
			ret.push_front(levelVec);
		}
		return vector<vector<int>>(ret.begin(), ret.end());
    }

	vector<vector<int>> levelOrderBottom2(TreeNode* root) {
		vector<vector<int> > ret;
		walk(root, 0, ret);
		return ret;
    }

	void walk(TreeNode* root, int depth, vector<vector<int>>& ret){
		if (!root){
			return;
		}
		if (depth == ret.size()){
			ret.insert(ret.begin(), vector<int>());
		}
		ret[ret.size() - 1 - depth].push_back(root->val);

		walk(root->left, depth + 1, ret);
		walk(root->right, depth + 1, ret);
	}
};
