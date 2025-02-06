#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
typedef long long ll;
const int MAX = 1000000;

ll t; // n
ll a, b; // n = a+b, 홀수 소수
bool visited[MAX+1]; // visited[i]=true면 i는 합성수.
ll primes[MAX+1]; //소수 집합
ll primecnt;

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

bool flag;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    setPrimes(1000000);
	// 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
    
    while (true) {
		cin >> t; // t is even.
		if (t == 0) break;
        for (ll tempA=0;tempA<primecnt;tempA++){
            ll tempB = t - primes[tempA];
            if(tempB<=2) continue;
            if (!visited[tempB]) {
                a = primes[tempA];
                b = tempB;
                flag = true;
                break;
            }
        }
		if (flag) cout << t << " = " << a << " + " << b << '\n';
		else cout << "Goldbach's conjecture is wrong." << '\n';
	}
	return 0;
}