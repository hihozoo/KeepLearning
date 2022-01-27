/**
 * 给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

进阶：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
		if (root){
			queue<Node*> que;
			que.push(root);
			while (!que.empty()){
				int size = que.size();
				Node* head = nullptr;
				while (size-- > 0){
					Node* cur = que.front();
					que.pop();

					if (head){
						head->next = cur;
					}
					head = cur;

					if (cur->left){
						que.push(cur->left);
					}
					if (cur->right){
						que.push(cur->right);
					}
				}
			}
		}
		return root;
	}

	// 降低空间复杂度
	// 如果第 ii 层节点之间已经建立 \text{next}next 指针，就可以通过 \text{next}next 指针访问该层的所有节点，同时对于每个第 ii 层的节点，我们又可以通过它的 \rm leftleft 和 \rm rightright 指针知道其第 i+1i+1 层的孩子节点是什么，所以遍历过程中就能够按顺序为第 i + 1i+1 层节点建立 \text{next}next 指针。
	Node* connect2(Node* root){
		Node* head = root;
		Node* dummy = new Node();

		while (head){
			Node* tmp = head;
			Node* cur = dummy;

			while (tmp){
				if (tmp->left){
					cur->next = tmp->left;
					cur = cur->next;
				}
				if (tmp->right){
					cur->next = tmp->right;
					cur = cur->next;
				}
				tmp = tmp->next;
			}

			head = dummy->next;
			dummy->next = nullptr;
		}
		delete dummy;
		return root;
	}
};