#include<iostream>

using namespace std;

struct Node{
	int key;
	Node* left;
	Node* right;
};

class Tree{
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
			return this->_insert(n->left, k);
		}
		else{
			return this->_insert(n->right, k);
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
	Tree * t = new Tree();

	int a [] = {4, 5, 1, 2, 3, 15, 10, 9, 8, 7};
	for (auto v: a){
		t->insert(v);
	}

	t->travel();

	cout << "the min in tree is :" << t->get_min() << endl;
	cout << "the max in tree is :" << t->get_max() << endl;
	// delete t;

	t->remove(4);
	t->travel();

	t->remove(5);
	t->travel();

	t->remove(3);
	t->travel();

	t->remove(2);
	t->travel();

	t->remove(4);
	t->travel();


	return 0;
}
