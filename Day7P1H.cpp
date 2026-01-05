#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
	int data;
	Node* parent;
	vector<Node*> children;
	Node(int data) {
		this->data = data;
		parent = nullptr;
	}
	~Node() = default;
	void insertChild(Node* child) {
		children.push_back(child);
	}
};

class Tree {
public:
	vector<Node*> list;
	Tree() {
		Node* root = new Node(1);
		list.push_back(root);
	}
	void insertNode(int parent_data, int data) {
		Node* parent = findNode(parent_data);
		if (parent == nullptr) {
			cout << -1 << endl;
		}
		else {
			Node* node = new Node(data);
			node->parent = parent;
			parent->children.push_back(node);
			list.push_back(node);
		}
	}
	Node* findNode(int data) {
		for (Node* node : list) {
			if (node->data == data) {
				return node;
			}
		}
		return nullptr;
	}
	void printChild(int parent_data) {
		Node* target = findNode(parent_data);
		if (target == nullptr) {
			cout << -1 << endl;
			return;
		}
		if (target->children.empty()) {
			cout << 0 << endl;
		}
		else {
			for (Node* node : target->children) {
				cout << node->data << " ";
			}
			cout << endl;
		}
	}
	void printDepth(int data) {
		cout << getDepth(data) << endl;
	}
	int getDepth(int data) {
		if (findNode(data) == nullptr) {
			return -1;
		}
		Node* cur = findNode(data);
		if (cur->parent == nullptr) {
			return 0;
		}
		return getDepth(cur->parent->data) + 1;
	}
};

int main() {
	int n;
	cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++) {
		string cmd;
		int x, y;
		cin >> cmd;
		if (cmd == "insert") {
			cin >> x >> y;
			tree.insertNode(x, y);
		}
		else if (cmd == "printChild") {
			cin >> x;
			tree.printChild(x);
		}
		else if (cmd == "printDepth") {
			cin >> x;
			tree.printDepth(x);
		}
	}
}