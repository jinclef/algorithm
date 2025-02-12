#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int VMAX = 20000;
const int EMAX = 300000;
const int SUMMAX = 10 * 20000;

typedef pair<int, int> pii;
// w<=10

vector<pii> adj[VMAX + 1]; // adj[u] = (v,w)
int dist[VMAX + 1]; // dist[x] = x까지의 최단거리
bool visited[VMAX + 1];

struct cmp {
	bool operator()(pii x, pii y) {
		return x.second > y.second;
	}
};

priority_queue<pii, vector<pii>, cmp> pq;

void dijkstra() {
	while (!pq.empty()) {
		int curr_v = pq.top().first;
		int curr_w = pq.top().second;

		pq.pop();
		if (visited[curr_v]) continue;
		visited[curr_v] = true;

		for (int i = 0; i < adj[curr_v].size(); i++) {
			pii next = adj[curr_v][i];
			int cand_w = curr_w + next.second;
			//pq.push({ next.first, cand_w });

			if (cand_w < dist[next.first]) {
				//visited[curr_v] = true;
				dist[next.first] = cand_w;
				pq.push({ next.first, cand_w });
			}
		}
	}

}

int V, e, k;
int main() { ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> V >> e;
	cin >> k;
	
	//memset(dist, SUMMAX, v);
	for (int i = 1; i <= V; i++) dist[i] = SUMMAX;

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w; // u->v, w
		adj[u].push_back({ v,w });
	}
	dist[k] = 0;
	pq.push({ k, 0 });
	dijkstra();

	for (int i = 1; i<=V; i++) {
		if (dist[i] == SUMMAX) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
	return 0;
 }
