#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	Node* parent;
	int data;
	vector<Node*> children;
	Node(int data) :data{ data } { parent = nullptr; }
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
			return;
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
	void preOrder(Node* v) {
		cout << v->data << " ";
		for (Node* node : v->children) {
			preOrder(node);
		}
	}
	void postOrder(Node* v) {
		for (Node* node : v->children) {
			postOrder(node);
		}
		cout << v->data << " ";
	}
	int getHeight() {
		int max = 0;
		for (int i = 0; i < list.size(); i++) {
			int depth = getDepth(list[i]->data);
			if (depth > max) {
				max = depth;
			}
		}
		return max;
	}
};

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Tree tree;
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int x, y;
			cin >> x >> y;
			tree.insertNode(x, y);
		}
		tree.preOrder(tree.list[0]);
		cout << endl;
		tree.postOrder(tree.list[0]);
		cout << endl;
		int depth = tree.getHeight();
		cout << depth << endl;
	}
}
