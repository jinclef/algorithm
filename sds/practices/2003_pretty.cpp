#include <iostream>

using namespace std;

int N, M;
int A[10001];
int sum, ans, s, e;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}


	while (s <= e && e <= N) {
		if (sum >= M) {
			if (sum == M)ans++;
			sum -= A[s];
			s++;
		}
		else {
			sum += A[e];
			e++;
		}
	}
	
	cout << ans << '\n';

	return 0;
}
