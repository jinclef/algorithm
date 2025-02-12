#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n==0) break;
    
        ll times=1;
        ll partpow = 10;
        while(times%n!=0){
            times += partpow;
            partpow*=10;
        }
        if(n==1) cout << 1 <<'\n';
        else cout << ceil(log10(times)) << '\n'; 
    }
    return 0;
}