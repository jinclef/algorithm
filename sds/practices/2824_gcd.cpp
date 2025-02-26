#include <iostream>
#include <queue>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

ll a,b;

priority_queue<ll, vector<ll>, greater<ll>> arr_a;
priority_queue<ll, vector<ll>, greater<ll>> arr_b;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    
    // 1. 소인수분해
    int n;
    cin >> n;

    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        for (int p=2; p<=sqrt(a); p++){
            while(a%p==0) {
                arr_a.push(p);
                a/=p;
            }
        }
        if(a>1) arr_a.push(a); // 소수
    }
    
    int m;
    cin >> m;
    for (int i=0;i<m;i++){
        int b;
        cin >> b;
        for (int p=2; p<=sqrt(b); p++){
            while(b%p==0) {
                arr_b.push(p);
                b/=p;
            }
        }
        if(b>1) arr_b.push(b); // 소수
    }

    // 2. 최대공약수 찾기
    ll gcd = 1;
    ll temp = 1;
    bool over_nine = false;
    const ll MOD = 1e9;

    while(!arr_a.empty() && !arr_b.empty()){
        ll prime = arr_a.top();
        if(arr_a.top() == arr_b.top()){ // A 기준으로 돌리고 남은 B는 필요 없음. -> 아님
            gcd = (gcd%MOD * prime%MOD) % MOD;
            if(!over_nine) {
                temp *= prime;
                if(temp >= MOD) over_nine = true;
            }
            arr_a.pop();
            arr_b.pop();
        } else{
            while(!arr_a.empty() && arr_a.top() < prime) arr_a.pop();
            while(!arr_b.empty() && arr_b.top() < prime) arr_b.pop();
            if(!arr_a.empty() && !arr_b.empty() && arr_b.top()!=arr_a.top()) arr_a.pop();
        }
    }

    if(over_nine){
        string final_gcd;
        int cnt = 9 - to_string(gcd).length();
        for(int i=0; i<cnt; i++){
            final_gcd += '0';
        }
        final_gcd += to_string(gcd);
        cout << final_gcd << '\n';

    } else{
        cout << gcd << '\n';
    }


    return 0;
}