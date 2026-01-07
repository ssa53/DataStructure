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

	void printDegree() {
		if (left == nullptr && right == nullptr) {
			cout << 0 << " ";
		}
		else if (left != nullptr && right != nullptr) {
			cout << 2 << " ";
		}
		else {
			cout << 1 << " ";
		}
	}

	void printDepth() {
		Node* cur = this;
		int d = 0;
		while (cur->parent != nullptr) {
			cur = cur->parent;
			d++;
		}
		cout << d << endl;
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
				return tmp;   //같으면 
			}
			else {
				if (tmp->data < data) {
					tmp = tmp->right;   //크면 
				}
				else {
					tmp = tmp->left;   //작으면 
				}
			}
		}
		return nullptr;
	}
	int getHeight(Node* node) {
		if (node!=nullptr) {
			return 0;
		}
		int leftHeight = getHeight(node->left);
		int rightHeight = getHeight(node->right);
		if (leftHeight > rightHeight) {
			return getHeight(node->left) + 1;
		}
		else {
			return getHeight(node->right) + 1;
		}
	}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		BST bst;
		for (int j = 0; j < n; j++) {
			int inp; cin >> inp;
			bst.insertNode(inp);
		}
		cout << bst.getHeight(bst.root) << endl;
	}
}

