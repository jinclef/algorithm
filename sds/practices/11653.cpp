#include <iostream>
#include <vector>


using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll NMAX = 10000000;

bool visited[NMAX+1];
vector<int> arrs; // 소수들

void eratos(int n) {
	for (ll i = 2; i <= n; i++) {
		if (visited[i]) continue;
		arrs.push_back(i);
		for (ll j = i * i; j <= n; j += i) {
			visited[j] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n;
	cin >> n;

	eratos(n);

	ll j = 0;
	while (n >= 1 && j < arrs.size()) {
		if (n%arrs[j]==0) {
			cout << arrs[j] << '\n';
			n /= arrs[j];
		}
		else {
			j++;
		}
	}

	return 0;
}
