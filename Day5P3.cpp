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
	int dequeue() {
		if (empty()) {
			cout << "Empty\n";
			return -1;
		}
		else {
			int val = q[f];
			f = (f + 1) % capacity;
			n--;
			return val;
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
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int size;
		cin >> size;
		arrayQueue q1(size);
		arrayQueue q2(size);
		int score1 = 0, score2 = 0;
		for(int j=0;j<size;j++){
			int inp;
			cin >> inp;
			q1.enqueue(inp);
		}
		for (int j = 0; j < size; j++) {
			int inp;
			cin >> inp;
			q2.enqueue(inp);
		}
		int bonus1 = 0;
		int bonus2 = 0;
		for (int j = 0; j < size; j++) {
			int card1 = q1.dequeue() + bonus1;
			int card2 = q2.dequeue() + bonus2;
			bonus1 = 0;
			bonus2 = 0;
			if (card1 > card2) {
				score1++;
				bonus1 = (card1 - card2) - 1;
			}
			else if (card1 < card2) {
				score2++;
				bonus2 = card2 - card1 - 1;
			}
		}
		if (score1 > score2) {
			cout << 1 << "\n";
		}
		else if (score1 < score2) {
			cout << 2 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}