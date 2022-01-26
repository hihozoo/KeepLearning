/**
 * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		return build(nums, 0, nums.size() - 1);
    }

	TreeNode* build(vector<int>& nums, int left, int right){
		if (left > right){
			return nullptr;
		}
		int mid = (left + right + 1) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = build(nums, left, mid - 1);
		root->right = build(nums, mid + 1, right);
		return root;
	}
};