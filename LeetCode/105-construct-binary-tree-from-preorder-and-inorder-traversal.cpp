/**
 * 给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return this->build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	TreeNode* build(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight){
		if (preLeft > preRight){
			return nullptr;
		}
		int val = preorder[preLeft];
		int val_index_of_inorder = inLeft;
		for (int i = 0; i <= inRight; i++){
			if (inorder[i] == val){
				val_index_of_inorder = i;
				break;
			}
		}
		int leftNum = val_index_of_inorder - inLeft;
		int rightNum = inRight - val_index_of_inorder;
		TreeNode* root = new TreeNode();
		root->val = preorder[preLeft];
		root->left = this->build(preorder, preLeft + 1, preLeft + leftNum, inorder, inLeft, val_index_of_inorder - 1);
		root->right = this->build(preorder, preLeft + leftNum + 1, preRight, inorder, val_index_of_inorder + 1, inRight);
		return root;
	}
};