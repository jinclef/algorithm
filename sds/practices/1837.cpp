#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX_VALUE = 1234567; // 10^6
bool composed[MAX_VALUE];
queue<ll> primenums;

void eratos(ll K){
    for (ll i=2;i<K;i++){
        if(composed[i]) continue;
        for (ll j=i*i; j<K;j+=i){
            if(composed[j]) continue;
            composed[j] = true;
        }
        primenums.push(i);
    }
}

queue<ll> privateKey;
bool bad = false;

string P;
int k;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> P;
    cin >> k;
    eratos(k);
    // cout << "eratosed: " << primenums.size() << '\n';

    ll ans = 0;
    while(!primenums.empty()){ // 약 10^6
        //init P
        for (ll i=0;i<P.length();i++){
            int pk = P[i] - '0';
            privateKey.push(pk);
        }

        // cout << "P to pk: " << privateKey.size() << '\n';
        
        ll dived = privateKey.front(); // 나눠지는 수
        ll diviee = primenums.front(); // 나누는 수
        privateKey.pop();

        while(!privateKey.empty()){ // 약 100번 정도.
            // cout << "(dived(" << dived << ") % diviee(" << diviee <<"))" << " * 10 + " << privateKey.front() << " = ";
            // cout << "dived % diviee: " << dived << "%" << diviee << "=" << dived % diviee << '\n';
            dived = (dived % diviee) * 10 + privateKey.front();
            // cout << dived << '\n';
            privateKey.pop();
        }
        
        if (dived % diviee == 0) {
            if (diviee == k) {
                bad = false;
            } else {
                bad = true;
                ans = diviee;
            }
            break;
        }
        primenums.pop();
    }
    if (bad) cout << "BAD" << ' ' <<  ans << '\n';
    else cout << "GOOD" << '\n';
    return 0;

}