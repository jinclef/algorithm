#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

typedef pair<int, ll> pll;

int n; // <= 100000
vector<pll> adj[100001];

// dijkstra 로 구현.
struct cmp_s {
	bool operator()(pll a, pll b) {
		return a.second > b.second;
	}
};

priority_queue<pll, vector<pll>, cmp_s> spq;
bool visited_s[100001];
ll sdist[100001];

void shortest() {
	while (!spq.empty()) {
		int curr_v = spq.top().first;
		ll curr_w = spq.top().second;

		spq.pop();
		if (visited_s[curr_v]) continue;
		visited_s[curr_v] = true;

		for (auto next : adj[curr_v]) {
			int next_v = next.first;
			ll next_w = next.second;
			ll candid = sdist[curr_v] + next_w;
			if (sdist[next_v] > candid) sdist[next_v] = candid;
		}
	}
}

struct cmp_l {
	bool operator()(pll a, pll b) {
		return a.second < b.second;
	}
};
priority_queue<pll, vector<pll>, cmp_l> lpq;
bool visited_l[100001];
ll ldist[100001];

void longest() {
	while (!lpq.empty()) {
		int curr_v = lpq.top().first;
		ll curr_w = lpq.top().second;

		lpq.pop();
		if (visited_l[curr_v]) continue;
		visited_l[curr_v] = true;

		for (auto next : adj[curr_v]) {
			int next_v = next.first;
			ll next_w = next.second;
			ll candid = ldist[curr_v] + next_w;
			if (ldist[next_v] < candid) ldist[next_v] = candid;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++) sdist[i] = 100000000000; // 1,000,000 * 100,000
	for (int i = 1; i <= n; i++) ldist[i] = 0;

	int k; // <= 100000
 	cin >> k;
	for (int i = 0; i < k; i++) {
		int d, e;
		cin >> d >> e;
		sdist[d] = 0;
		ldist[d] = 100000000000;

		spq.push({ d, sdist[d] });
		lpq.push({ d, ldist[d] });

		shortest();
		longest();

		cout << sdist[e] << ' ' << ldist[e] << '\n';
		for (int i = 1; i <= n; i++) { // 초기화
			visited_s[i] = false;
			visited_l[i] = false;
			sdist[i] = 100000000000;
			ldist[i] = 0;
		}
	}
	return 0;
}
