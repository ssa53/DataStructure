#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Edge {
public:
	int u, v;
	string word;
	Edge(int _u, int _v, string _w) :u(_u), v(_v), word(_w) {};
};

class Graph {
private:
	Edge* matrix[2001][2001];
	bool vertexExists[2001];
	vector<Edge*> totalEdgeList;
	int n;
	int edgeCount;
public:
	Graph() {
		for (int i = 0; i < 2001; i++) {
			vertexExists[i] = false;
			for (int j = 0; j < 2001; j++) {
				matrix[i][j] = nullptr;
			}
		}
		n = 0;
		edgeCount = 0;
	}
	void insertVertex(int id) {
		if (!vertexExists[id]) {
			vertexExists[id] = true;
			n++;
		}
	}
	void insertEdge(int u, int v, string word) {
		if (!vertexExists[u] || !vertexExists[v] || matrix[u][v]!=nullptr) {
			cout << -1 << endl;
			return;
		}
		Edge* newEdge = new Edge(u, v, word);
		matrix[u][v] = matrix[v][u] = newEdge;
		totalEdgeList.push_back(newEdge);
		edgeCount++;
	}
	void printStatus() {
		cout << n << " " << edgeCount << endl;
	}
	void eraseVertex(int id) {
		if (!vertexExists[id]) {
			cout << -1 << endl;
			return;
		}
		
		vertexExists[id] = false;
		n--;

		vector<Edge*> finalEdgeList;
		for (Edge* e : totalEdgeList) {
			if (e->u == id || e->v == id) {
				matrix[e->u][e->v] = matrix[e->v][e->u] = nullptr;
				delete e;
				edgeCount--;
			}
			else {
				finalEdgeList.push_back(e);
			}
		}
		totalEdgeList = finalEdgeList;

		cout << edgeCount;
		for (Edge* e : totalEdgeList) {
			cout << " " << e->word;
		}
		cout << endl;
	}
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	Graph* g = new Graph();

	for (int i = 0; i < n; i++) {
		int id; cin >> id;
		g->insertVertex(id);
	}

	for (int i = 0; i < m; i++) {
		int u, v; string word;
		cin >> u >> v >> word;
		g->insertEdge(u, v, word);
	}

	g->printStatus();

	for (int i = 0; i < k; i++) {
		int id; cin >> id;
		g->eraseVertex(id);
	}

	delete g;
}