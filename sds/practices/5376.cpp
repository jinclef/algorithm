#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

ll my_pow(int n, int a) {
	// n^a
	ll res=1;
	for (int i = 0; i < a; ++i) {
		res *= n;
	}
	return res;

}

ll find_gcd(ll x, ll y) {
	ll r;
	while (y) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

void makeFrac(string decimal) {
	int dotIdx = decimal.find(".");
	int openIdx = decimal.find("(");
	int closeIdx = decimal.find(")");

	string fixed, repeated;

	if (openIdx == -1) { // 0.xxx
		fixed = decimal.substr(dotIdx+1);
		repeated = "";
	}else {
		if (openIdx - dotIdx - 1 == 0) { // 0.(yyy)
			fixed = "";
		}
		else { // 0.xxx(yyy)
			fixed = decimal.substr(dotIdx+1, openIdx - dotIdx - 1);
		}
		repeated = decimal.substr(openIdx+1, closeIdx - openIdx - 1);
	}

	ll dived, divy;
	// CHANGE TO FRACTION
	if (openIdx == -1) {
		// 0.3, 0.5 같이 그냥 수.
		dived = stoll(fixed);
		divy = my_pow(10, fixed.length());
		//cout << dived << " 나누기 " << divy << '\n';
	}
	else {
		if (fixed == "") { // 0.(yyy)
			dived = stoll(repeated);

			ll divy_mul = 0;
			for (int i = 0; i < repeated.length(); i++) {
				divy_mul += my_pow(10, i);
			}
			divy = 9 * divy_mul;
			//cout << dived << " 나누기 " << divy << '\n';
		}
		else {
			// 0.xxx(yyy)
			ll divy_mul = 0;
			for (int i = 0; i < repeated.length(); i++) {
				divy_mul += my_pow(10, i);
			}
			string entire = fixed + repeated;
			dived = stoll(entire) - stoll(fixed);
			//cout << divy_mul << '\n';
			divy = 9 * divy_mul * my_pow(10, fixed.length());
			//cout << dived << " 나누기 " << divy << '\n';
		}
	}

	ll gcd = find_gcd(dived, divy);
	cout << dived / gcd << '/' << divy / gcd << '\n';

	//cout << "FIXED: " << fixed << ", REPEATED: " << repeated << '\n';
	return;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string a;
		cin >> a;
		makeFrac(a);
	}

	return 0;
}
