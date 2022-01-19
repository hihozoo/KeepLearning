/**
 * 返回与给定的前序和后序遍历匹配的任何二叉树。
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

class Solution
{
public:
	TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder){
		return construct(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
	}

	TreeNode *construct(vector<int> &preorder, int preLeft, int preRight,
		vector<int> &postorder, int postLeft, int postRight)
	{
		if (preLeft > preRight){
			return nullptr;
		}
		TreeNode* root = new TreeNode();
		root->val = preorder[preLeft];
		if (preLeft == preRight){
			return root;
		}
		int val_index_of_post = postLeft;
		for (int i = postLeft; i <= postRight; i++){
			if (postorder[i] == preorder[preLeft + 1]){
				val_index_of_post = i;
				break;
			}
		}
		int leftNum = val_index_of_post - postLeft + 1;
		int rightNum = postRight - val_index_of_post - 1;

		root->left = construct(preorder, preLeft + 1, preLeft + leftNum,
						postorder, postLeft, val_index_of_post);
		root->right = construct(preorder, preLeft + leftNum + 1, preRight,
						postorder, val_index_of_post + 1, postRight - 1);
		return root;
	}

	TreeNode* PrePost(vector<int>& preorder, vector<int>& postorder, int l1, int h1, int l2, int h2){
        if(l1 > h1){
            return NULL;
        }
        TreeNode *root = new(TreeNode);
        root->val = preorder[l1];//根节点
        if(l1==h1){
            return root;
        }
        int index; //左子树的根结点下标在后序中的序号
        for(index=0;postorder[index]!=preorder[l1+1]; index++); //在后序序列中找左子树根结点下标

        int l_len = index-l2+1; //左子树长度
        int r_len = h2-1-index; //右子树长度

        root->left = PrePost(preorder, postorder, l1+1, l1+l_len, l2, index); //左子树构建
        root->right = PrePost(preorder, postorder, h1-r_len+1, h1, index+1, index+r_len); //右子树构建
        return root;
    }
};