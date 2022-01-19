/**
 * 给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：

二叉树的根是数组 nums 中的最大元素。
左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
返回有给定数组 nums 构建的 最大二叉树 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return this->constructMaxiumBinaryTreeImpl(nums, 0, nums.size() - 1);
	}

	TreeNode* constructMaxiumBinaryTreeImpl(vector<int>& nums, int left, int right){
		if (left > right || left >= nums.size()){
			return nullptr;
		}
		int max_value = nums[left];
		int max_value_index = left;
		for (int i = left + 1; i <= right; i++){
			if (nums[i] > max_value){
				max_value = nums[i];
				max_value_index = i;
			}
		}
		TreeNode * root = new TreeNode();
		root->val = nums[max_value_index];
		root->left = this->constructMaxiumBinaryTreeImpl(nums, left, max_value_index - 1);
		root->right = this->constructMaxiumBinaryTreeImpl(nums, max_value_index + 1, right);
		return root;
	}
};
