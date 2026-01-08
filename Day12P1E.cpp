#include<iostream>
#include<vector>

#define MAX 353333
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

int hashfunc(int idx);
void insertLinear(int key);
void searchLinear(int key);
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

void clear() {
	for (int i = 0; i < MAX; i++) {
		hashArr[i].value = -1;
		hashArr[i].key = -1;
		hashArr[i].flag = NOITEM;
	}
	sz = 0;
}

void searchLinear(int key) {
	int idx = hashfunc(key);
	int p = 1;
	int startIdx = idx; 

	while (hashArr[idx].flag != NOITEM) { 
		if (hashArr[idx].flag == ISITEM && hashArr[idx].key == key) {
			cout << 1 << " " << p << endl; 
			return;
		}
		idx = (idx + 1) % MAX;
		p++;

		if (idx == startIdx) break; 
	}
	cout << 0 << " " << p << endl; 
}

void deleteLinear(int key) {
	
}

void insertLinear(int key) {
	cell c;
	c.key = key; //key가 key 인 cell c 생성. 
	//비어있는 공간이 나올 때까지 계속 조사. 
	int idx = hashfunc(c.key);
	//while (hashArr[hashfunc(key)].flag != NOITEM) 
	while (hashArr[idx].flag != NOITEM) {
		idx = (idx + 1) % MAX;
	}
	hashArr[idx] = c;//flag 바꿔. 
	hashArr[idx].flag = ISITEM;
	sz++;
}

int hashfunc(int idx) {
	return idx % MAX;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		clear();
		int n; cin >> n;
		for (int j = 0; j < n; j++) {
			int inp;
			cin >> inp;
			insertLinear(inp);
		}
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			int inp;
			cin >> inp;
			searchLinear(inp);
		}
	}
}