/**
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <climit>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
		vector<int> lastVal;
		return isValidBST(root, lastVal);
	}

	// 利用中序遍历是一个升序数列的结果
	bool isValidBST(TreeNode* root, vector<int>& lastVal){
		if (!root){
			return true;
		}
		if (!isValidBST(root->left, lastVal)){
			return false;
		}
		if (lastVal.size() == 0){
			lastVal.push_back(root->val);
		}else{
			if (root->val <= lastVal[0]){
				return false;
			}
			lastVal[0] = root->val;
		}
		if (!isValidBST(root->right, lastVal)){
			return false;
		}
		return true;
	}
};