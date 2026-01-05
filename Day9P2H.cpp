#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Heap {
public:
	vector<int> v;
	int heap_size;
	int root_idx;
	int mode;
	Heap(int mode) {
		v.push_back(-1);
		this->heap_size = 0;
		this->root_idx = 1;
		this-> mode = mode;
	}
	void insert(int e) {
		v.push_back(e);
		heap_size++;
		upheap(heap_size);
	}
	void upheap(int idx) {
		int parent_idx = idx / 2;
		if (idx == root_idx) {
			return;
		}
		parent_idx = idx / 2;
		if (v[parent_idx]*mode > v[idx]*mode) {
			swap(parent_idx, idx);
			upheap(parent_idx);
		}
	}
	void swap(int x, int y) {
		int tmp = v[x];
		v[x] = v[y];
		v[y] = tmp;
	}
	void cap() {
		cout << heap_size << endl;
	}
	void isEmpty() {
		if (heap_size == 0) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	void print(int idx) {
		cout << v[idx] << endl;
	}

	void pop() { //root 출력하고 제거, 맨뒤원소를 루트로 올리고 다운힙;
		if (heap_size == 0) {
			return;
		}
		v[1] = v[heap_size];
		v.pop_back();
		heap_size--;
		if (heap_size > 0) {
			downHeap(1);
		}
	}
	void downHeap(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		int min = idx;
		if (left <= heap_size && v[left]*mode < v[min]*mode) {
			min = left;
		}
		if (right <= heap_size && v[right]*mode < v[min]*mode) {
			min = right;
		}
		if (min != idx) {
			swap(idx, min);
			downHeap(min);
		}
	}
	void sorted_print(int idx) {
		vector<int> newv;
		while (heap_size > 0) {
			newv.push_back(v[1]);
			pop();
		}
		cout << newv[idx - 1] << endl;
	}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		Heap heap(1);
		Heap maxheap(-1);
		int n; int p;
		cin >> n >> p;
		for (int j = 0; j < n; j++) {
			int inp;
			cin >> inp;
			heap.insert(inp);
			maxheap.insert(inp);
		}
		heap.print(p);
		heap.sorted_print(p);
		maxheap.print(p);
		maxheap.sorted_print(p);
	}
}
