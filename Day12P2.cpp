#include<iostream>
#include<vector>

#define MAX 353333
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

int hashfunc(int idx);
int hashfunc2(int idx);
void clear();

class cell {
public:
	int key;
	int value;
	int flag;
	cell() {
		key = -1;
		value = -1;
		flag = NOITEM;
	}
	~cell() {}
};

cell hashArr[MAX];
int sz = 0;

void insertDouble(int key) {
	int h1 = hashfunc(key);
	int h2 = hashfunc2(key);
	int idx = h1;

	while (hashArr[idx].flag == ISITEM) {
		idx = (idx + h2) % MAX;
	}
	
	hashArr[idx].key = key;
	hashArr[idx].flag = ISITEM;
}

void searchDouble(int key) {
	int h1 = hashfunc(key);
	int h2 = hashfunc2(key);
	int idx = h1;
	int p = 1;

	while (hashArr[idx].flag != NOITEM) {
		if (hashArr[idx].flag == ISITEM && hashArr[idx].key == key) {
			cout << 1 << " " << p << endl;
			return;
		}
		idx = (idx + h2) % MAX;
		p++;
		if (p > MAX) {
			break;
		}
	}
	cout << 0 << " " << p << endl;
}

void clear() {
	for (int i = 0; i < MAX; i++) {
		hashArr[i].value = -1;
		hashArr[i].key = -1;
		hashArr[i].flag = NOITEM;
	}
	sz = 0;
}


int hashfunc(int idx) {
	return idx % MAX;
}

int hashfunc2(int idx) {
	return (17 - (idx % 17));
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		clear();
		for (int j = 0; j < n; j++) {
			int inp; cin >> inp;
			insertDouble(inp);
		}
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			int inp; cin >> inp;
			searchDouble(inp);
		}
	}
}