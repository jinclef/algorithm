#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
long long arr[4][4002];
vector<long long> ab;
vector<long long> cd;

int main(){
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
   
    /*for (int i=0;i<pow(n,2);++i){
        cout << ab[i] << ' ' ;
    }
    cout << '\n';
    for (int i=0;i<pow(n,2);++i){
        cout << cd[i] << ' ';
    }
    cout << '\n';*/

   // ab: -> , cd: <-
   int vectlen = pow(n,2);
   int abidx=0, cdidx=vectlen-1, ans=0;
   while(abidx<vectlen && cdidx<vectlen){
        long long sum = ab[abidx] + cd[cdidx];
    
        // cout << abidx << ": " << ab[abidx] << ", " << cdidx <<  ": " << cd[cdidx] << ", sum: " << sum << '\n';
        if(sum == 0){
            ans++;
            // cout << "success: " << ans << '\n'; 
            // idx 옮기기
            int tempA=0;
            int tempB=0;
            while(ab[abidx] == ab[++abidx]) tempA++;
            while(cd[cdidx] == cd[--cdidx]) tempB++;
            // cout << "updated idx: " << abidx << " " << cdidx << '\n';
            ans += (tempA*tempB);
        }
        else if(sum > 0) cdidx--;
        else /* sum<0 */ abidx++;
    }

    cout << ans << '\n';
    return 0;
}