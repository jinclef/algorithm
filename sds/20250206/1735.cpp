#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int a, b, c, d;
ll gcd;

int main() {
	// 분자, 분모
	cin >> a >> b;
	cin >> c >> d;

	// 두 분수의 합
	ll sumTop = a * d + b * c;
	ll sumBottom = b * d;

	// 기약분수로 나타내기: 분자와 분모의 GCD를 찾아서 나눠준다.
	ll a = max(sumTop, sumBottom);
	ll b = min(sumTop, sumBottom);
	
	// gcd
	while (b != 0) {
		 ll r = a % b;
		a = b;
		b = r;
	}
	gcd = a;

	ll top = sumTop / gcd;
	ll bottom = sumBottom / gcd;

	cout << top << ' ' << bottom << '\n';
	return 0;
}
