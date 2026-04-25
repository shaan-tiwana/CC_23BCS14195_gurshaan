#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int V, const vector<vector<int>>& adj) {
	vector<int> inDegree(V, 0);
	for (int u = 0; u < V; ++u) {
		for (int v : adj[u]) {
			++inDegree[v];
		}
	}
	queue<int> q;
	for (int i = 0; i < V; ++i) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	vector<int> result;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		result.push_back(u);
		for (int v : adj[u]) {
			--inDegree[v];
			if (inDegree[v] == 0) {
				q.push(v);
			}
		}
	}
	return result;
}

int main() {
	int V, E;
	cin >> V >> E;
	vector<vector<int>> adj(V);
	for (int i = 0; i < E; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	vector<int> order = topologicalSort(V, adj);
	for (int node : order) {
		cout << node << ' ';
	}
	cout << '\n';
	return 0;
}
