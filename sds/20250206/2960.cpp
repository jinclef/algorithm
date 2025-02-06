#include <iostream>
using namespace std;
typedef long long ll;

int n, k;
bool deleted[1001];

int getpnlist(int n, int k) { // delete composite number, getpnlist, find k
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		for (ll j = i; j <= n; j += i) { // i^2 ~ N 중에서 i 배수 찾기
			if (deleted[j]) continue;
			deleted[j] = true;
			cnt++;
			if (k == cnt) return j;
		}
	}
}

int main() {
	cin >> n >> k; // k번째 지우는 수 구하기
	cout << getpnlist(n, k) << '\n';
	return 0;
}
