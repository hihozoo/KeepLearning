/**
 * 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int> > ret;
		if (!root){
			return ret;
		}
		deque<TreeNode*> deq;
		deq.push_back(root);

		bool isOrderLeft = true;

		while (!deq.empty()){
			int size = deq.size();
			deque<int> levelList;
			while (size-- > 0){
				TreeNode* node = deq.front();
				deq.pop_front();

				if (isOrderLeft){
					levelList.push_back(node->val);
				}else{
					levelList.push_front(node->val);
				}

				if (node->left){
					deq.push_back(node->left);
				}
				if (node->right){
					deq.push_back(node->right);
				}
			}
			ret.push_back(vector<int>(levelList.begin(), levelList.end()));
			isOrderLeft = !isOrderLeft;
		}
		return ret;
	}
};

