#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Heap {
public:
	vector<int>v;
	int root_idx;
	int heapsize;
	Heap() {
		v.push_back(-1);
		this->heapsize = 0;
		this->root_idx = 1;
	}
	void insert(int e) {
		v.push_back(e);
		heapsize++;
		upheap(heapsize);
	}
	void upheap(int idx) {
		int parent = idx / 2;
		if (idx == root_idx) {
			return;
		}
		if (v[parent] > v[idx]) {
			swap(parent, idx);
			upheap(parent);
		}
	}
	void size() {
		cout << heapsize << endl;
	}
	void isEmpty() {
		if (heapsize == 0) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	void pop() {
		if (heapsize == 0) {
			cout << -1 << endl;
			return;
		}

		cout << v[1] << endl;

		v[1] = v[heapsize];
		v.pop_back();
		heapsize--;
		if (heapsize > 0) {
			downHeap(1);
		}
	}
	void swap(int x, int y) {
		int temp = v[x];
		v[x] = v[y];
		v[y] = temp;
	}
	void downHeap(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		int min = idx;
		if (left <= heapsize && v[left] < v[min]) {
			min = left;
		}
		if (right <= heapsize && v[right] < v[min]) {
			min = right;
		}
		if (min != idx) {
			swap(idx, min);
			downHeap(min);
		}
	}
	void top() {
		if (heapsize == 0) {
			cout << -1 << endl;
			return;
		}
		cout << v[1] << endl;
	}
	void print() {
		if (heapsize == 0) {
			cout << -1 << endl;
		}
		else {
			for (int i = 1; i < heapsize + 1; i++) {
				cout << v[i] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	int n;
	cin >> n;
	Heap heap;
	for (int i = 0; i < n; i++) {
		string cmd; cin >> cmd;
		if (cmd == "insert") {
			int x;
			cin >> x;
			heap.insert(x);
		}
		else if (cmd == "size") {
			heap.size();
		}
		else if (cmd == "isEmpty") {
			heap.isEmpty();
		}
		else if (cmd == "top") {
			heap.top();
		}
		else if (cmd == "pop") {
			heap.pop();
		}
		else if (cmd == "print") {
			heap.print();
		}
	}
}