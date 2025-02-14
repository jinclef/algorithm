#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX= 100000;
const int INF = -10001; // 안 들어올 수

vector<int> arr;
priority_queue<int> lt; // back 작 -- 큰 front // front 가 큰거

struct cmp{
    bool operator()(int a, int b){
        return a>b;
    }
};
priority_queue<int, vector<int>, cmp> gt; // back 작 -- 큰 front // front 가 작은거

int mid;
int l=INF;
int r=-INF; // l: [mid-1], r: [mid+1]

int mididx(){ // 1부터 센다고 하자.
    return lt.size()-1 + (l==INF ? 0 : 1) + 1;
}

void update(int x, int all){
    // cout << "mididx: " << mididx() << ", haveto: " << (all+1)/2 << '\n';
    if(x==mid){
        if(mididx() == (all+1)/2) {gt.push(r); r=x;}// 그냥 아무데나 넣어도 됨.
        else {
            lt.push(l);
            l = x;
        }
    }
    else if(mid<x && x<r){ // mid 오른쪽에 삽입을 해야 하는 경우
        if(mididx() < (all+1)/2){
            // lt로 밀어낸다.
            lt.push(l);
            l = mid;
            mid = x;
        } else {
            // 뒤로 밀어
            gt.push(r);
            r = x;
        }
    } else if(l<x&&x<mid){ // mid 왼쪽에 삽입을 해야 하는 경우
        if(mididx() < (all+1)/2){
            lt.push(l);
            l = x;
        } else {
            gt.push(r);
            r = mid;
            mid = x;
        }
    } else { // mid에는 영향을 안주는 경우
        if(mididx() == (all+1)/2){
            if(x>=r) gt.push(x);
            else if(x<=l) {
                gt.push(r);
                r = mid;
                mid = l;
                l=max(lt.top(), x);
                if(lt.top() >= x) {
                    lt.pop();
                    lt.push(x);
                }
            }
        } else{
            if(x<=l) lt.push(x);
            else if(x>=r){
                lt.push(l);
                l=mid;
                mid=r;
                r =  min(x, gt.top());
                if(gt.top() <= x){
                    gt.pop();
                    gt.push(x);
                }
            }
        }
    }
    // cout << "lt.top: " << (lt.empty() ? -1 : lt.top()) << '\n';
    // cout << "gt.top: " << (gt.empty() ? -1 : gt.top()) << '\n';
    // cout << "l, m, r"<<'\n';
    // cout << l << ", " << mid << ", " << r << '\n'; 
}

int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    for (int i=1; i<=n;i++){
        int a;
        cin >> a;
        if(i==1) mid = a;
        else if(i==2) {
            if(mid <= a) r = a; // 등호는 어디가든 상관없음 어차피 두개밖에 없어서.
            else if(mid > a) r = mid;

            mid = min(mid, a);
        } else if(i>=3){ // 3
            // cout << "insert " << a << " when " << i << '\n';
            update(a, i);
            // cout << "update done = ";
        }
        // cout << "i: " << i << ", answer: " <<  mid << '\n';
        cout << mid << '\n';
    }

    return 0;
}