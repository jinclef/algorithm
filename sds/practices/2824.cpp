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
bool visited[1001];

void eratos(){
    for(int i=2;i<=1000;i++){
        if(visited[i]) continue;
        for(int j=i*i;j<=1000;j+=i){
            visited[j]=true;
        }
        factor.push_back(i);
    }
}

int main(){
    eratos();

    cin >> n;
    for (int i=0;i<n;i++){
        ll na;
        cin >> na; // 다 곱하면 A. 즉 A의 인수..?
        int j=0;
        while(na>1){
            if(na%factor[j]==0){ // 나눠떨어지면 그거 소인수임.
                na/=factor[j];
                arr.push(factor[j]);
            }else{
                j++;
            }
        }
    }

    cin >> m;
    for (int i=0;i<m;i++){
        ll ma;
        cin >> ma;
        int j=0;
        while(ma>1){
            if(ma%factor[j]==0){
                ma/=factor[j];
                arr_m.push(factor[j]);
            }else{
                j++;
            }
        }
    }

    ll gcd = 1;
    int i=0;
    while(arr_m.size()>0 && arr.size()>0){
        if(arr.top()==factor[i] && arr_m.top()==factor[i]){
            gcd *= factor[i];
            arr.pop();
            arr_m.pop();
        } else{
            while(arr.top()<=factor[i]) arr.pop();
            while(arr_m.top()<=factor[i]) arr_m.pop();
            i++;
        }
    }
    // const int NINE = 1000000000;
    // if(gcd >= NINE){
    //     ll final_gcd = gcd % 1000000000;
    //     string final;
    //     int cnt = 9 - log10(final_gcd)/10;
    //     for(int i=0; i<cnt; i++){
    //         final += '0';
    //     }
    //     final += to_string(final_gcd);
    //     cout << final << '\n';
    // }

    cout << gcd << '\n';
    return 0;
}