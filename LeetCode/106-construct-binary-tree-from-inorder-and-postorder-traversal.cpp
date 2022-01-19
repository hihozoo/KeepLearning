/**
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
*/
#include <iostream>
#include <vector>

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return this->build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

	TreeNode* build(vector<int>& inorder, int inLeft, int inRight, vector<int>& postorder, int postLeft, int postRight){
		if (inLeft > inRight){
			return nullptr;
		}
		int val_index_of_inorder = inLeft;
		for (int i = inLeft; i <= inRight; i++){
			if (inorder[i] == postorder[postRight]){
				val_index_of_inorder = i;
				break;
			}
		}
		int leftNum = val_index_of_inorder - inLeft;
		int rightNum = inRight - val_index_of_inorder;
		TreeNode* root = new TreeNode();
		root->val = postorder[postRight];
		root->left = this->build(inorder, inLeft, val_index_of_inorder - 1, postorder, postLeft, postLeft + leftNum - 1);
		root->right = this->build(inorder, val_index_of_inorder + 1, inRight, postorder, postLeft + leftNum, postRight - 1);
		return root;
	}
};