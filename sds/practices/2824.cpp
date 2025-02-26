#include <iostream>
#include <queue>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

ll a,b;
struct cmp{
    bool operator()(ll a, ll b){
        return a>b;
    }
};

priority_queue<ll, vector<ll>, cmp> arr;
priority_queue<ll, vector<ll>, cmp> arr_m;

ll n, m;
vector<ll> factor;
const ll MAX_VALUE = 1000000001; // 10^9 + 1
const ll LIMIT_VALUE = 31625; // > sqrt(10^9)
bool visited[LIMIT_VALUE];

void eratos(){
    for(ll i=2;i <= LIMIT_VALUE;i++){
        if(visited[i]) continue;
        for(ll j=i*i;j<=LIMIT_VALUE;j+=i){
            visited[j]=true;
        }
        factor.push_back(i);
    }
}

int main(){
    eratos();

    cin >> n;
    for (ll i=0;i<n;i++){
        ll na;
        cin >> na; // 다 곱하면 A. 즉 A의 인수..?
        ll j=0;
        while(na>1 && j<factor.size()){
            if(na%factor[j]==0){ // 나눠떨어지면 그거 소인수임.
                na/=factor[j];
                arr.push(factor[j]);
            }else{
                j++;
            }
        }
    }

    cin >> m;
    for (ll i=0;i<m;i++){
        ll ma;
        cin >> ma;
        ll j=0;
        while(ma>1 && j<factor.size()){
            if(ma%factor[j]==0){
                ma/=factor[j];
                arr_m.push(factor[j]);
            }else{
                j++;
            }
        }
    }

    // while(arr.size()>0){
    //     cout << arr.top() << ' ';
    //     arr.pop();
    // }

    // cout << '\n';

    // while(arr_m.size()>0){
    //     cout << arr_m.top() << ' ';
    //     arr_m.pop();
    // }

    ll gcd = 1;
    ll i=0;
    while(arr_m.size()>0 && arr.size()>0 && i<factor.size()){
        // cout << factor[i] << '\n';
        if(arr.top()==factor[i] && arr_m.top()==factor[i]){
            gcd *= factor[i];
            arr.pop();
            arr_m.pop();
        } else{
            while(arr.size() > 0 && arr.top()<=factor[i]) {
                // cout << "arr pop: " << arr.top();
                arr.pop();
            }
            // cout << '\n';
            while(arr_m.size() > 0 && arr_m.top()<=factor[i]) {
                // cout << "arr_m pop: " << arr_m.top();
                arr_m.pop();
            }
            // cout << '\n';
            i++;
        }
    }
    const int NINE = 1000000000;
    if(gcd >= NINE){
        ll final_gcd = gcd % 1000000000;
        // cout << "final_gcd: " << final_gcd << '\n';
        string final;
        int cnt = 9 - to_string(final_gcd).length();
        for(int i=0; i<cnt; i++){
            final += '0';
        }
        final += to_string(final_gcd);
        cout << final << '\n';
    } else {
        cout << gcd << '\n';
    }
    return 0;
}