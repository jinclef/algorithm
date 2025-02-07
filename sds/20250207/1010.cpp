#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

typedef pair<ll, ll> pll;
map<pll, int> comb;

ll fact(int n) {
	int ans = 1;
	for (int i = n; i >= 1; i--) {
		ans *= i;
	}
	return ans;
}

ll combination(int n, int k) {
	ll res = 1ll;
	if (comb[{n, k}]) return comb[{n, k}];
	else {
		if (n <= 1 || k == 0) res = 1; // 1ck, 0ck, nc0
		else if (k == 1 || n - k == 1) res = n; // nc1
		else if (n == k) res = 1; // ncn
		else res = combination(n - 1, k - 1) + combination(n - 1, k);
		//cout << n << " c " << k << '\n';
		comb[{n, k}] = res;
		comb[{n, n - k}] = res;
		return res;
	}
}

ll bridges(int n, int m) {
	if (n > m) return 0;
	if (n == m) return 1;
	ll cnt = 0;
	//초기값 설정: west[0]-east[0]
	int a = n-1; 
	int b = m-1;

	for (int b=m-1;b>=a;b--){
		cnt += combination(b,a);
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int t, N, M;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		cin >> N >> M;
		cout << bridges(N, M) << '\n';
	}

	return 0;
}
