#include<iostream>
using namespace std;

bool matrix[2001][2001];
bool v[2001];

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < 2001; i++) {
		v[i] = false;
		for (int j = 0; j < 2001; j++) {
			matrix[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		int inp;
		cin >> inp;
		v[inp] = true;
	}
	
	int edgeCount = 0;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (!v[x] || !v[y]) {
			cout << -1 << endl;
			continue;
		}
		if (matrix[x][y]) {
			cout << -1 << endl;
		}
		else {
			matrix[x][y] = matrix[y][x] = true;
			edgeCount++;
		}
	}

	cout << n << " " << edgeCount << endl;
	
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		if (!v[a] || !v[b]) {
			cout << -1 << endl;
		}
		else {
			if (matrix[a][b]) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
	}
}

