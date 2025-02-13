#include <iostream>
using namespace std;
typedef long long ll;
int partsum[1025][1025]; // 각 행마다 합

ll sum(int x1, int y1, int x2, int y2) {
	ll res = 0;
	for (int i = x1; i <= x2; i++) {
		res += partsum[i][y2] - partsum[i][y1-1];
			}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			partsum[i][j] += partsum[i][j - 1] + a;
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum(x1, y1, x2, y2) << '\n';
	}

	return 0;
}
