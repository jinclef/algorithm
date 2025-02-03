#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

bool bsearch(int l, int r, int target, int* narr){
    int idx = (l+r)/2;
    if(target == narr[idx]) return true;

    if (l <= idx && idx < r){
        if (target < narr[idx]){
            return bsearch(l, idx, target, narr);
        } else if (target > narr[idx]){
            return bsearch(idx+1, r, target, narr);
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);
    int M;
    cin >> M;
    for (int j=0;j<M;j++){
        int k;
        cin >> k;
        int res = bsearch(0, N-1, k, arr) ? 1 : 0;
        cout << res << '\n';
    }

    return 0;
}