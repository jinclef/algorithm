#include <iostream>
using namespace std;
typedef long long ll;

ll x,y;
int main(){
    cin >> x >> y;
    ll z = y * 100 / x;
    ll m = y*100 % x;

    // k*(100-z) + m >= x+k?
    ll c1 = 100-z;
    ll c2 = m;
    ll c3 = x;

    if(c1-1 == 0) cout << -1 << '\n';
    else {
        ll value = (c3-c2) / (c1-1);
        ll mvalue = (c3-c2) % (c1-1);
        if (value < 0) cout << -1 << '\n';
        else {
            if(mvalue == 0) cout << value << '\n';
            else cout << value +1 << '\n';
        }
    }

    return 0;
}