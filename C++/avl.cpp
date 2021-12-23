#include<iostream>
#include<algorithm>

using namespace std;

/**
 * 缺点，插入有序序列的时候，将会倾斜，退化成链表。
*/

struct Node{
	int key;
	Node* left;
	Node* right;

	int height(){
		int h = 0;
		if (this->left){
			h = max(this->left->height() + 1, h);
		}
		if (this->right){
			h = max(this->right->height() + 1, h);
		}
		return h;
	}

	int height_diff(){
		int h = 0;
		if (this->left){
			h = this->left->height();
		}
		if (this->right){
			h -= this->right->height();
		}
		return abs(h);
	}
};

class AvlTree{
public:
	Node * root;

	Node * find(int key){
		return this->_find(this->root, key);
	}

	Node* _find(Node* n, int k){
		if (!n){
			return NULL;
		}
		if (k == n->key){
			return n;
		}
		else if (k > n->key){
			return this->_find(n->right, k);
		}else {
			return this->_find(n->left, k);
		}
	}

	bool insert(int key){
		return this->_insert(this->root, key);
	}

	bool _insert(Node*& n, int k){
		if (!n){
			n = new Node();
			n->key = k;
			return true;
		}
		if (n->key == k){
			return false;
		}
		else if (n->key > k){
			bool b = this->_insert(n->left, k);
			if (b && n->height_diff() > 1){
			}
			return b;
		}
		else{
			bool b = this->_insert(n->right, k);
			if (b && n->height_diff() > 1){
			}
			return b;
		}
	}

	void travel(){
		this->_travel(this->root);
		cout << endl;
	}

	bool remove(int k){
		return this->_remove(this->root, k);
	}

	bool _remove(Node*& n, int k){
		if (!n){
			return false;
		}
		if (n->key == k){
			if (n->left){
				Node * p = n;
				Node * q = n->left;
				while(q->right){
					p = q;
					q = q->right;
				}
				n->key = q->key;
				if (p != n){
					p->right = q->left;
				}else{
					p->left = q->right;
				}
			}else if (n->right){
				Node * p = n;
				Node * q = n->right;
				while (q->left)
				{
					p = q;
					q = q->left;
				}
				n->key = q->key;
				if (p != n){
					p->left = q->right;
				}else{
					p->right = q->left;
				}
			}else{
				n = NULL;
			}
			return true;
		}
		else if (n->key > k){
			return this->_remove(n->left, k);
		}else{
			return this->_remove(n->right, k);
		}
	}

	void _travel(Node* n){
		if (!n){
			return;
		}
		this->_travel(n->left);
		cout << n->key << " ";
		this->_travel(n->right);
	}

	int get_min(){
		Node *n = this->_get_min_node(this->root);
		if (n){
			return n->key;
		}
		return 0;
	}

	Node* _get_min_node(Node *n){
		if (!n){
			return nullptr;
		}
		if (n->left){
			return this->_get_min_node(n->left);
		}
		return n;
	}

	int get_max(){
		Node * n = this->_get_max_node(this->root);
		if (n){
			return n->key;
		}
		return 0;
	}

	Node* _get_max_node(Node* n){
		if (!n){
			return NULL;
		}
		if (n->right){
			return this->_get_max_node(n->right);
		}
		return n;
	}
};

int main(){
	AvlTree * t = new AvlTree();

	int a [] = {4, 5, 1, 2, 3, 15, 10, 9, 8, 7};
	for (auto v: a){
		t->insert(v);
	}

	return 0;
}
