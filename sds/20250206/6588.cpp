#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll t; // n
ll a, b; // n = a+b, 홀수 소수
bool visited[1000001];
ll primes[1000001];
//vector<ll> primes;
ll primecnt;

void clearPrimeset() {
	for (int i = 0; i < primecnt; i++) {
		primes[i] = 0;
	}
	primecnt = 0;
}

void setPrimes(ll n) {
	for (ll i = 2; i<=n; ++i) {
		for (ll j = i * i; j <= n; j += i) {
			if (visited[j]) continue;
			visited[j] = true;
		}
	}
	for (ll i = 2; i < n; ++i) {
		if (visited[i] == false) {
			primes[primecnt] = i;
			primecnt++;
		}
	}
}
ll mymax;
bool trygold(ll idxA, ll idxB, ll NminusA, ll n) { // back tracking 해서 당첨되면 바로 out
	if (primes[idxB] > NminusA) return false;

	bool res = false;
	while (idxA < idxB && idxB >=0) {
		ll nminusa = n - primes[idxA];
		if (primes[idxA] <= 2 || nminusa <= 2) {
			idxA++; continue;
		}
		//cout << "while: " << primes[idxA] << ' ' << primes[idxB]  << ' ' << nminusa << '\n';
		if (visited[nminusa]) { // 만들어야 되는 수가 짝수인 경우
			idxA++; continue;
		}
		if (primes[idxB] == nminusa) {
			a = primes[idxA];
			b = primes[idxB];
			res = true;
			//cout << "hi? " << a << " + " << b << '\n';
			mymax = max(mymax, b - a);
			break;
		}
		else {
			idxB--;
		}
	}
	if (idxA == idxB) return false;
	else {
		return true;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	// 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
	while (true) {
		clearPrimeset();
		cin >> t; // test cases
		setPrimes(t);
		if (t == 0) break;
		/*for (ll i = 0; i < primecnt; i++) {
			cout << primes[i] << ' ';
		}
		cout << '\n';*/
		trygold(0, primecnt - 1, t, t);
		if (mymax !=0) cout << a << " + " << b << '\n';
		else cout << "Goldbach's conjecture is wrong." << '\n';
	}
	return 0;
}