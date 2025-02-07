#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

map<pll, int> comb;
const int divisor = 10007;

ll combination(int n, int k) {
	ll res = 1LL;
	if (comb[{n, k}]) return comb[{n, k}]%divisor;
	else {
		if (n <= 1 || k == 0) res = 1; // 1Ck, 0Ck, nC0
		else if (k == 1 || n - k == 1) res = n; // nC1
		else if (n == k) res = 1; // nCn
		else res = combination(n - 1, k - 1) + combination(n - 1, k);
		comb[{n, k}] = res;
		comb[{n, n - k}] = res;
		return res%divisor;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	ll bino_coff = combination(n, k);
	cout << bino_coff << '\n';

	return 0;
}
