#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> A;
vector<int> B;

int t, n, m;
int start_a, start_b, end_a, end_b; // =0
long long sum;

int main(){
    cin >> t; // <= 10^9

    cin >> n;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    cin >> m;
    for (int i=0;i<m;i++){
        int b;
        cin >> b;
        B.push_back(b);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // cout << "A: " ;
    // for (int i=0;i<n;i++){
    //     cout << A[i] << ' ';
    // }
    // cout << "\nB: ";
    // for (int i=0;i<m;i++){
    //     cout << B[i] << ' ';
    // }
    // cout<< '\n';

    // init
    sum = A[0] + B[0];
    int cnt = 0;
    while(start_a <= end_a && start_b <= end_b && end_a<n && end_b<m && start_a>=0 && end_a>=0){
        if (sum > t){
            if(B[start_b] < A[start_a]) {
                sum -= B[start_b];
                if(start_b <= end_b) start_b++;
            } else {
                sum -= A[start_a];
                if(start_a <= end_a) start_a++;
            }
        } else if(sum < t){ // sum <= t
            if(end_a+1>=n) {
                end_b++;
                if(end_b < m) sum += B[end_b];
            }
            else if (end_b+1>=m) {
                end_a++;
                if(end_a < n) sum += A[end_a];
            }
            else {
                if(B[end_b+1] <= A[end_a+1]){
                    end_b++;
                    if(end_b < m) sum += B[end_b];
                } else {
                    end_a++;
                    if(end_a < n) sum += A[end_a];
                }
            }
        } else{ // sum == t
            cout << start_a << '~' << end_a << '+' << start_b << '~' << end_b << '\n';
            cnt++;
            if(B[end_b] < A[end_a]){
                end_b++;
                if(end_b<m) sum += B[end_b];
            } else {
                end_a++;
                if(end_a<n) sum += A[end_a];
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}