// 구간 합 구하기

// 1. 구간 합 -> 2 pointer
// 2. 근데 값 변경 -> tree

#include <iostream>
using namespace std;
typedef long long ll;

int n,m,k;

int arr[1000002];
int main(){
    cin >> n >> m >> k;
    
    for (int i=1;i<=n;i++){
        cin >> arr[i];
    }

    for (int i=0;i<m+k;i++){
        ll a,b,c;
        cin >> a >> b>> c;
        if (a==1){
            arr[b] = c;
        } else if (a==2){
            ll sum = 0;
            for (int j=b; j<=c; j++){
                sum += arr[j];
            }
            cout << sum << '\n';
        }
    }

    return 0;
}