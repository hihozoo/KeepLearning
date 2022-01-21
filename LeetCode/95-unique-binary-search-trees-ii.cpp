/**
 * 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
*/

#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};


class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
		return generateTrees(1, n);
    }

	vector<TreeNode*> generateTrees(int left, int right){
		if (left > right){
			return {nullptr};
		}
		vector<TreeNode*> vec;
		for (int i = left; i <= right; i++){
			vector<TreeNode*> lt = generateTrees(left, i - 1);
			vector<TreeNode*> rt = generateTrees(i + 1, right);
			for (auto lv: lt){
				for (auto rv: rt){
					TreeNode* root = new TreeNode();
					root->val = i;
					root->left = lv;
					root->right = rv;
					vec.push_back(root);
				}
			}
		}
		return vec;
	}

};