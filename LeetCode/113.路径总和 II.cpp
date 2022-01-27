/**
 * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <algorithm>

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int> > ret;
		vector<int> tmp;
		pathSum(root, targetSum, tmp, ret);
		return ret;
    }

	void pathSum(TreeNode* root, int targetSum,
				vector<int>& vec, vector<vector<int> >& ret){
		if (!root){
			return;
		}
		targetSum -= root->val;
		vec.push_back(root->val);
		if (targetSum == 0){
			if (!root->left && !root->right){
				ret.push_back(vec);
			}
		}
		pathSum(root->left, targetSum, vec, ret);
		pathSum(root->right, targetSum, vec, ret);
		vec.pop_back();
	}
};