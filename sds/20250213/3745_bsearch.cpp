#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 100000;

int arr[MAX+1];
vector<int> q;

int findIdx(int value) { // 나보다 큰 값 중에 가장 작은 값을 나로 바꾼다.
	int left = 0; int right = q.size() - 1;
	int mid = 0;
	while (left < right) {
		mid = (left + right) / 2;
		if (value == q[mid]) {
			// 같은값이 있따? 바꿀 필요 없음.
			return -1;
		}
		
		if (value > q[mid]) { // 내가 더 크면 안됨.
			left = mid+1;
			continue;
		}
		else { // value <= q[mid] : 내가 더 작으면 교체 후보임
			right = mid;
			continue;
		}
	}
	return left; // = right
}

int main() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	while (cin >> n) {
		q.clear();
		for (int i = 0; i < n; i++) cin >> arr[i];
		q.push_back(arr[0]); // empty

		for (int i = 1; i < n; i++) {
			if (arr[i] > q[q.size()-1]) q.push_back(arr[i]);
			else {
				int idx = findIdx(arr[i]);
				if (idx == -1) continue;
				else q[idx] = arr[i];
			}
		}
		cout << q.size() << '\n';
	}
	return 0;
}
