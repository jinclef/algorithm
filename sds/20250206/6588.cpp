#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll t; // n
ll a, b; // n = a+b, 홀수 소수
bool visited[1000001]; // visited[i]=true면 i는 합성수.
ll primes[1000001]; //소수 집합
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
ll mymax=-1;
bool trygold(ll idxA, ll idxB, ll NminusA, ll n) { // back tracking 해서 당첨되면 바로 out
	bool res = false;
	while (idxA <= idxB && idxB >=0) { //idxA와 이룰 수 있는 쌍 찾기
		ll nminusa = n - primes[idxA];

        if (primes[idxB] > nminusa) {
            idxB--;
            continue;
        }

		if (primes[idxA] <= 2 || nminusa <= 2) { // 홀수 소수의 합이어야 함. 즉 2는 안됨.
			idxA++;
            continue;
		}

		//cout << "while: " << primes[idxA] << ' ' << primes[idxB]  << ' ' << nminusa << '\n';
		if (visited[nminusa]) { // 만들어야 되는 수(b)가 합성수인 경우
			idxA++; continue;
		}

		if (primes[idxB] == nminusa) {
			a = primes[idxA];
			b = primes[idxB];
			res = true;
			//cout << "hi? " << a << " + " << b << '\n';
			mymax = max(mymax, b - a); // b-a가 0인데?
			break;
		}
		else {
			idxB--;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	// 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
	while (true) {
		clearPrimeset();
		cin >> t; // t is even.
		setPrimes(t);
		if (t == 0) break;
		/*for (ll i = 0; i < primecnt; i++) {
			cout << primes[i] << ' ';
		}
		cout << '\n';*/
		trygold(0, primecnt - 1, t-primes[0], t);
		if (mymax !=-1) cout << t << " = " << a << " + " << b << '\n';
		else cout << "Goldbach's conjecture is wrong." << '\n';
	}
	return 0;
}