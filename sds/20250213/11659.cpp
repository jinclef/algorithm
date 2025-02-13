#include <iostream>
using namespace std;
typedef long long ll;
const int MAX = 100000;
int arr[MAX + 1];
ll partsum[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		partsum[i+1] = partsum[i] + arr[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		ll res = partsum[b] - partsum[a-1];
		cout << res << '\n';
	}
	return 0;
}
