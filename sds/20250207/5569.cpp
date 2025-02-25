#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int cross[101][101];

int w,h;
// 집 (1,1), 회사 (w,h)

int cntPath(int fromX, int fromY, char dir, bool canTurn, ll cnt){ //dir: 그 점으로 온 방향.
    cout << "cntPath: " << fromX << ' ' << fromY << ' ' << dir << ' '<< (canTurn ? "straight" : "turn....") << ' ' << cnt << '\n';
    
    if(fromX > w || fromX < 1 || fromY > h || fromY < 1) return 0;
    if (fromX==w && fromY==h) return 1;

    if(!canTurn){ // 직진
        if(dir=='u') return cntPath(fromX, fromY+1, 'u', true, cnt+1);
        else /* 'r' */ return cntPath(fromX+1, fromY, 'r', true, cnt+1);
    } else {// 둘다 가능: 꺾음 + 직진
        if(dir=='u') return cntPath(fromX+1, fromY, 'r', false, cnt+1) + cntPath(fromX, fromY+1, 'u', true, cnt+1);
        else /* 'r' */ return (cntPath(fromX, fromY+1, 'u', false, cnt+1) + cntPath(fromX+1, fromY, 'r', true, cnt+1));
    }
}
int main() { ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> w >> h;

    ll pathCnt = cntPath(1,1,'u',true, 0) + cntPath(1,1,'r', true, 0);
    cout << pathCnt << '\n';

	return 0;
}