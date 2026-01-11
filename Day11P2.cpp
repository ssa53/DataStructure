#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {
public:
	int data;
	Node* parent;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}

	~Node() = default;

	void insertlChild(Node* left) {
		this->left = left;
		left->parent = this;
	}

	void insertrChild(Node* right) {
		this->right = right;
		right->parent = this;
	}

};

class BST {
public:
	Node* root;
	int height;

	BST() {
		root = nullptr;
		height = 0;
	}

	~BST() {
		treeDestructor(root);
	}
	void treeDestructor(Node* root) {
		if (root == nullptr) {
			return;
		}
		if (root->left != nullptr) {
			this->treeDestructor(root->left);
		}
		if (root->right != nullptr) {
			this->treeDestructor(root->right);
		}
		delete root;
	}
	void insertNode(int data) {
		Node* v = new Node(data);
		if (root == nullptr) {
			root = v;
			return;
		}
		else {
			Node* cur = root;
			Node* par = nullptr;
			while (cur != nullptr) {
				par = cur;
				if (cur->data < data) {
					cur = cur->right;
				}
				else {
					cur = cur->left;
				}
			}
			if (par->data > data) {
				par->insertlChild(v);
			}
			else {
				par->insertrChild(v);
			}
		}
	}

	Node* findNode(int data) {
		Node* tmp = root;
		while (tmp != nullptr) {
			if (tmp->data == data) {
				return tmp;   //°°À¸¸é 
			}
			else {
				if (tmp->data < data) {
					tmp = tmp->right;   //Å©¸é 
				}
				else {
					tmp = tmp->left;   //ÀÛÀ¸¸é 
				}
			}
		}
		return nullptr;
	}
	Node* treeMinimum(Node* x) {
		while (x->left != nullptr) {
			x = x->left;
		}
		return x;
	}
	void transplant(Node* u, Node* v) {
		if (u->parent == nullptr) {
			root = v;
		}
		else if (u == u->parent->left) {
			u->parent->left = v;
		}
		else { 
			u->parent->right = v;
		}
		if (v != nullptr) {
			v->parent = u->parent;
		}
	}
	void eraseNode(int data) {
		Node* v = findNode(data);
		if (v == nullptr) {
			return;
		}
		if (v->left == nullptr) {
			transplant(v,v->right);
		}
		else if (v->right == nullptr) {
			transplant(v, v->left);
		}
		else {
			Node* y = treeMinimum(v->right);
			if (y->parent != v) {
				transplant(y, y->right);
				y->right = v->right;
				y->right->parent = y;
			}
			transplant(v, y);
			y->left = v->left;
			y->left->parent = y;
		}
		delete v;
	}
	void preOrder(Node* v) {
		if (v == nullptr) {
			return;
		}
		cout << v->data << " ";
		preOrder(v->left);
		preOrder(v->right);
	}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		BST bst;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int inp;
			cin >> inp;
			bst.insertNode(inp);
		}
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int inp;
			cin >> inp;
			bst.eraseNode(inp);
		}
		bst.preOrder(bst.root);
		cout << endl;
	}
}


