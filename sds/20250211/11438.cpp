#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
const int KMAX = 20;

int n, m;
vector<int> adj[MAX];
int depth[MAX];
int parent[MAX][KMAX];

void dfs(int curr) {  // 부모-자식 연결
	for (auto next : adj[curr]) {
		if (depth[next] != 0) continue;
		depth[next] = depth[curr] + 1;
		parent[next][0] = curr;
		dfs(next);
	}
}

void initLCA() {
	depth[1] = 0; // root: 1
	dfs(1);

	for (int k = 0; k < KMAX; k++) {
		for (int i = 1; i <= n; i++) {
			int temp = parent[i][k];
			if (temp != 0) parent[i][k + 1] = parent[temp][k];
		}
	}
}

int lca(int x, int y) {
	if (x == y) return x;
	if (depth[x] == depth[y]) {
		for (int i = KMAX-1; i >= 0; i--) {
			if (parent[x][i] != parent[y][i]) {
				x = parent[x][i];
				y = parent[y][i];
			}
		}
		return parent[x][0];
	}
	else {
		int diff = abs(depth[x] - depth[y]);
		int j = 0;

		while (diff) { // 같은 높이로 맞춰준다.
			if (diff % 2) {
				if (depth[x] > depth[y]) x = parent[x][j];
				else y = parent[y][j];
			}
			j++;
			diff /= 2;
		}

		return lca(x, y);
	}
}


int main() { ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) adj[a].push_back(b);
		else if (b == 1) adj[b].push_back(a);
		else {
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	initLCA();

	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
	return 0;
}
