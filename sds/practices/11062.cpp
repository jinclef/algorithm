#include <iostream>
#include <deque>
using namespace std;
typedef long long ll;

int arr[1001]; // 카드

deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			dq.push_front(a);
		}
		// 근우 먼저. k%2=0이면 근우 차례. 1이면 명우 차례.
		ll score = 0;
		for (int k = 0; k < n; k++) {
			if (dq.front() > dq.back()) {
				if (k % 2 == 0) score += dq.front();
				dq.pop_front();
			}
			else {
				if (k % 2 == 0) score += dq.back();
				dq.pop_back();
			}// 근데 만약에 앞뒤가 같으면 어떡해? 몰라
		}

		cout << score << '\n';
	}
	return 0;
}
