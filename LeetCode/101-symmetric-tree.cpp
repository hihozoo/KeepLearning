/**
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> left;
        stack<TreeNode*> right;

		TreeNode* root_left = root;
		TreeNode* root_right = root;

		while ((root_left || !left.empty()) || (root_right || !right.empty())){
			while (root_left && root_right){
				left.push(root_left);
				right.push(root_right);
				root_left = root_left->left;
				root_right = root_right->right;
			}
			if (root_left || root_right){
				return false;
			}
			root_left = left.top();
			root_right = right.top();
			left.pop();
			right.pop();
			if (root_left->val != root_right->val){
				return false;
			}
			root_left = root_left->right;
			root_right = root_right->left;
		}
    }

	bool isSymmetric(TreeNode*p, TreeNode*q){
		if (!p && !q){
			return true;
		}
		if (p && q){
			if (p->val != q->val){
				return false;
			}
			return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
		}
		return false;
	}
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        bool ret = Solution().isSymmetric(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}