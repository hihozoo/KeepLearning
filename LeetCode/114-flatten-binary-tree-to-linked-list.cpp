/**
 * 给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
    void flatten(TreeNode* root) {
		if (!root){
			return;
		}
		flatten(root->left);
		flatten(root->right);

		swap(root->left, root->right);

		TreeNode* right = root;
		while (right->right != nullptr){
			right = right->right;
		}
		right->right = root->left;
		root->left = nullptr;
	}
};

int main(){
	return 0;
}