#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, long> pil; // idx - memory
typedef pair<int, int> pii; // idx - cost

const int INF = 100000000000000;

vector<pil> memory;
vector<pii> cost;
vector<pil> memcost;

bool cmp(pil a, pil b) { // cost, mem
	if (a.first != b.first) return a.first < b.first; // cost 작은 순
	else return a.second > b.second; // cost 같으면 mem 큰 순
}

bool cmp2(pil a, pil b) { // mem 작은 순 -> 차근차근 cost 줄이기.
	if (a.second != b.second) return a.second < b.second;
	return a.first > b.first;
}

//void debug() {
//
//	cout << "mincost: " << mincost << '\n';
//	cout << "tempcost: " << tempcost << '\n';
//	cout << "tempmem: " << tempmem << '\n';
//	cout << "l: " << l << ", memcost[l].first: " << memcost[l].first << ", memcost[l].second: " << memcost[l].second << '\n';
//	cout << "r: " << r << ", memcost[r].first: " << memcost[r].first << ", memcost[r].second: " << memcost[r].second << '\n';
//
//}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) { // A의 메모리 바이트 수
		int a;
		cin >> a;
		memory.push_back(pii(i, a));
	}
	for (int i = 1; i <= n; i++) { // A 비활성화 비용
		int c;
		cin >> c;
		cost.push_back(pii(i, c));
	}

	for (int i = 0; i < n; i++) {
		memcost.push_back(pil(cost[i].second, memory[i].second));
	}

	// 정렬: cost 작은 순 -> 같으면 memory 큰 순
	sort(memcost.begin(), memcost.end(), cmp);

	/*for (int i = 0; i < memcost.size(); i++) {
		cout << memcost[i].first << ' ' << memcost[i].second << '\n';
	}*/

	int r = 0;
	ll mincost = INF;
	ll tempcost = memcost[0].first;
	ll tempmem = memcost[0].second;
	ll limit = memcost.size();

	while (tempmem < m && r< memcost.size() - 1) {
		r++;
		tempcost += memcost[r].first;
		tempmem += memcost[r].second;
	}
	limit = r;
	mincost = tempcost;
	if (mincost == 0) { cout << mincost << '\n'; return 0; }
	
	// 덜어내기
	sort(memcost.begin(), memcost.end(), cmp2);
	int l = limit - 1;
	while (l >=0) {
		if (tempmem - memcost[l].second >= m) { // 아직 크면 괜찮음.
			tempmem -= memcost[l].second;
			mincost -= memcost[l].first;
		}
		l--;
	}

	cout << mincost << '\n';

	return 0;
}
