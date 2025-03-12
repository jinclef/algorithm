// 구간 합 구하기

// 1. 구간 합 -> 2 pointer
// 2. 근데 값 변경 -> tree

#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

const ll MAXINT = 1048576; // 2^20
ll n,m,k;

ll arr[MAXINT*2]; // 1이 tree 의 top, leaf node 는 MAXINT부터 시작. (1... 2^20-1, 2^20...)

void printTree(){
    for (int i=1;i<=MAXINT*2;i*=2){
        if(arr[i]==0) continue;
        else {
            for(int j=i;j<i*2;j++){
                if(arr[j]!=0) cout << j << ' ' << arr[j] << ' ';
            }
            cout << endl;
        }
    }
}

void update(int x, ll v){ // x번째 수 변경
    int idx = MAXINT + (x-1);
    arr[idx] = v;
    while(idx>1){
        if(idx%2==0) {
            arr[idx/2] = arr[idx]+arr[idx+1];
        }
        else {
            arr[idx/2] = arr[idx-1]+arr[idx];
        }
        idx/=2;
    }
}


ll findSubsum(int target_s, int target_e, int node_s, int node_e, ll node_idx){ // target_s ~ target_e 까지의 합
    ll sum = 0;
    ll idx = 1;
    ll node_mid = (node_s + node_e) / 2;

    // 0. 관련 없는 경우
    if(node_e < target_s || node_s > target_e) return 0;
    // 1. node가 target에 포함되거나 같으면 그 node 그대로 반환
    else if(target_s <= node_s && target_e >= node_e) return arr[node_idx];
    // // 2. 아예 밖이면 양쪽 다 비교하기
    // if(node_s < target_s && target_e < node_e) return findSubsum(target_s, target_e, node_s, node_mid, node_idx*2) + findSubsum(target_s, target_e, node_mid+1, node_e, node_idx*2+1);
    // // 3. node가 target에 걸치면 mid끼리 비교하기
    // else{
    //     int target_mid = (target_s + target_e) / 2;
    //     if(node_mid >= target_mid) return findSubsum(target_s, target_e, node_s, node_mid, node_idx*2); // 왼쪽
    //     else return findSubsum(target_s, target_e, node_mid+1, node_e, node_idx*2+1); // 오른쪽
    // }
    else {
        return findSubsum(target_s, target_e, node_s, node_mid, node_idx*2) + findSubsum(target_s, target_e, node_mid+1, node_e, node_idx*2+1);
    }
}


int main(){
    cin >> n >> m >> k;
    
    for (int i=1;i<=n;i++){
        ll a;
        cin >> a;
        update(i, a);
    }

    // printTree();

    for (int i=0;i<m+k;i++){
        ll a,b,c;
        cin >> a >> b>> c;
        if (a==1){
            update(b,c);
            // printTree();
        } else if (a==2){
            cout << findSubsum(b-1, c-1 ,0, MAXINT-1, 1) << '\n';
        }
    }

    return 0;
}