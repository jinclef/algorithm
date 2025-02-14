#include <iostream>
using namespace std;
typedef long long ll;

int n;
ll m;
int A[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}

	// 기저
	ll sum = A[1];
	int l = 1; int r = 1;
	int cnt = 0;

	while (l <= r && r <= n && l>=1) {
		if (sum < m) {
			r++;
			sum += A[r];
		}
		else if (sum > m) {
			if (l == r) { // 이렇게 처리해주는게 맞다고?
				r++;
				sum += A[r];
			}
			sum -= A[l];
			l++;
		}
		else { // sum == m
			cnt++;
			sum -= A[l];
			r++; l++;
			sum += A[r];
		}
	}
	cout << cnt << '\n';
	return 0;
}
