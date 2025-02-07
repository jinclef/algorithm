#include <iostream>
using namespace std;
typedef long long ll;

ll fact(int n) {
	int ans = 1;
	for (int i = n; i >=1; i--) {
		ans *= i;
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	ll res = fact(n) / (fact(n - k)*fact(k));
	cout << res << '\n';

	return 0;
}
