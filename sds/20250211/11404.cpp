#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 10000000;

int n;
int m; // max 100,000
ll dist[101][101];

void printi() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) cout << "INF ";
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				/*cout << "i: " << i << ", j: " << j << ", k: " << k << '\n';
				printi();*/
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}
}


int main() {
	cin >> n;
	cin >> m;

	// initialize
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			dist[i][j] = (i == j) ? 0 : INF;
		}
	}
	
	// input
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c); // 같은출발-같은 도착 간선 입력이 여러개 주어질 수 있기 때문.
	}

	// floyd-warshall
	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	
	return 0;
}
