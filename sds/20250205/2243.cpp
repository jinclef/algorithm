#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

const ll MAX = (1<<18);

ll tree[2*MAX];
ll favor[1000000];
ll treeSize;

int n; // <= 100,000

void constructTree(){
    for (int i=0;i<1000000;++i){
        tree[MAX+i] = favor[i];
    }
    for (int i=MAX-1; i>=0; --i){
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

void putCandy(int idx, int num){ // update
    tree[MAX+idx] +=num;
    // 부모 업데이트
    while(idx>1){
        idx/=2;
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }
}

ll search(int idx, int num){
    if(idx >= treeSize) return -1;
    if(tree[idx] == num) return idx;
    else if (tree[idx] > num) {
        ll res = search(idx*2, num);
        if(res!= -1) res = search(idx*2+1, num);
        if (res==-1) return idx;
    }
}

ll getCandy(int rank){
    ll res = search(0, rank);
    if (res!= -1){
        if (tree[res] == rank) putCandy(rank, -tree[res]);
        else ;
    }
    return 0;
}

int main(){
    cin >> n;
    int power = ceil(log(1000000) / log(2));
    ll mymax = pow(2, power);
    treeSize = 2*mymax;

    for (int i=0;i<n;++i){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        if (a==1) getCandy(b);
        else if(a==2) putCandy(b,c);
    }
    return 0;
}