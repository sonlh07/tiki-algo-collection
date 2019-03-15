#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[101];
bool mark[101];
int n, m;
int cnt = 0;

void dfs(int u) {
	mark[u] = true;
	cnt++;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (mark[v] == false) {
			dfs(v);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	if (cnt == n && m == n - 1) {
		cout << "YES";
	}
	else
		cout << "NO";
	return 0;
}