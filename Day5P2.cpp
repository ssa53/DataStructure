#include <iostream>
#include <string>
using namespace std;

class arrayQueue {
public:
	int* q;
	int capacity;
	int n;
	int f;
	int r;
	arrayQueue(int s) {
		capacity = s;
		n = 0;
		f = 0;
		r = 0;
		q = new int[s];
	}
	~arrayQueue() {
		delete[] q;
	}
	int size()const {
		return n;
	}
	bool empty() const {
		return (n == 0);
	}
	void enqueue(int x) {
		if (n == capacity) {
			cout << "Full\n";
			return;
		}
		else {
			q[r] = x;
			r = (r + 1) % capacity;
			n++;
		}
	}
	void dequeue() {
		if (empty()) {
			cout << "Empty\n";
			return;
		}
		else {
			int val = q[f];
			f = (f +1) % capacity;
			n--;
			cout << val <<  "\n";
		}
	}
	void front()const {
		if (empty()) {
			cout << "Empty\n";
			return;
		}
		else {
			cout << q[f] << "\n";
		}
	}
	void rear()const {
		if (empty()) {
			cout << "Empty\n";
			return;
		}
		else {
			cout << q[(r - 1 + capacity) % capacity] << "\n";
		}
	}
};

int main() {
	int s, m;
	cin >> s;
	cin >> m;
	arrayQueue q(s);
	for (int i = 0; i < m; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "size") {
			cout << q.size() << "\n";
		}
		else if (cmd == "isEmpty") {
			cout << (q.empty() ? 1 : 0) << "\n";
		}
		else if (cmd == "enqueue") {
			int x;
			cin >> x;
			q.enqueue(x);
		}
		else if (cmd == "dequeue") {
			q.dequeue();
		}
		else if (cmd == "front") {
			q.front();
		}
		else if (cmd == "rear") {
			q.rear();
		}
	}
}