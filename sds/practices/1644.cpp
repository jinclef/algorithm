#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll NMAX = 4000000;

ll cnt,N;
vector<int> parr;
bool visited[NMAX+1];

ll countNum(){
    ll start = 0, end = 0;
    ll sum = 2;

    while(start<=end && end<parr.size()){
        if(sum == N){
            cnt++;
            sum -= parr[start];
            start++;
            end++;
            sum += parr[end];
            // sum=0;
            // for (int i=start;i<=end;i++){
            //     sum += parr[i];
            // }

        }
        else if(sum>N) {
            sum-=parr[start];
            start++;
        }
        else {
            end++;
            sum+=parr[end];
        }

        // cout << "res sum: " << start << ' ' << end << ' ' << sum << '\n';
    }

    return cnt;
}

void makeParr(){
    for (ll i=2;i<=N;i++){
        if(visited[i]) continue;
        else parr.push_back(i);
        for (ll j=i*i;j<=N;j+=i){
            if(visited[j]) continue;
            else {
                visited[j] = true;
            }
        }
    }
}

int main(){
    cin >> N;
    makeParr();

    // for (int i=0;i<30;i++){
    //     cout << parr[i] << ' ';
    // }
    // cout <<'\n';

    cout << countNum() << '\n';

    return 0;
}