#include<iostream>
#include<vector>
using namespace std;

bool mat[2001][2001];
bool v[2001];

int main() {
	int n; 
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int inp;
		cin >> inp;
		v[inp] = true;
	}
	int edgeCnt = 0;
	for (int i = 0; i < m; i++) {
		int s, d;
		cin >> s >> d;
		if (!v[s] || !v[d]) {
			cout << -1 << endl;
			continue;
		}
		if (mat[s][d]==true) {
			cout << -1 << endl;
			continue;
		}
		mat[s][d] = mat[d][s] = true;
		edgeCnt++;
	}
	cout << n << " " << edgeCnt << endl;
}