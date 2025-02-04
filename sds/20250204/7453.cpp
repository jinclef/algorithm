#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; // <=4000
long long arr[4][4002];
vector<long long> ab;
vector<long long> cd;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    // 입력 받기
    cin >> n;
    for (int i=0;i<n;++i){
        for(int j=0;j<4;++j){
            cin >> arr[j][i];
        }
    }

    /*for (int i=0;i<4;++i){
        for(int j=0;j<n;++j){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }*/

    //두 배열의 합 조합 배열
    for (int i=0;i<n;++i){
        long long a = arr[0][i];
        long long c = arr[2][i];
        for(int j=0;j<n;++j){
            long long b = arr[1][j];
            ab.push_back(a+b);
            long long d = arr[3][j];
            cd.push_back(c+d);
        }
    }
    /*for (int i=0;i<pow(n,2);++i){
        cout << ab[i] << '\t' << cd[i] << '\n';
    }*/

   // ab[m], cd[n]의 합이 0인 경우의 수 찾기
   // 일단은 정렬
   sort(ab.begin(), ab.end());
   sort(cd.begin(), cd.end());
   
    // for (int i=0;i<n*n;++i){
    //     cout << "(" << i << "," << ab[i] << ") " ;
    // }
    // cout << '\n';
    // for (int i=0;i<n*n;++i){
    //     cout << "(" << i << "," << cd[i] << ") " ;
    // }
    // cout << '\n';

   // ab: -> , cd: <-
   int vectlen = n*n;
   int abidx=0, cdidx=vectlen-1, ans=0;
   
   while(abidx<vectlen && cdidx>=0){
        long long sum = ab[abidx] + cd[cdidx];
    
        // cout << abidx << ", " << cdidx << ", sum: " << sum << '\n';
        if(sum == 0){
            // cout << "success: " << ans << ' ' << abidx << ' ' << cdidx << '\n'; 
            // is there more 0 near?
            int tempA=1;
            int tempB=1;
            long long tempabv = ab[abidx];
            long long tempcdv = cd[cdidx];
            while((abidx+tempA<vectlen) && (ab[abidx+tempA] == tempabv)) {
                tempA++;
            }
            while((cdidx-tempB>=0) && (cd[cdidx-tempB] == tempcdv)) {
                tempB++;
            }
            ans += (tempA*tempB);
            
            // no more same value
            abidx+=tempA;
            cdidx-=tempB;

            // cout << "updated idx: " << abidx << " " << cdidx << '\n';
        }
        else if(sum > 0) cdidx--;
        else /* sum<0 */ abidx++;
    }

    cout << ans << '\n';
    return 0;
}