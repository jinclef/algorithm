// 카펫
#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

int w,h;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // 4*3 -> brown 4*2 + 3*2 - 4 = 10, yellow = (4-2)*(3-2) = 2
    // brown = 2*(w+h) - 4
    // yellow = (w-2) * (h-2)
    ll area = brown + yellow; // w*h. max = 2005000
    for (ll tempW=2; tempW<2005000; tempW++){
        double tempH = (double)area / tempW;
        if (tempH != (int)tempH) continue; // 안나눠떨어지는 경우
        else if(tempW < tempH) continue;
        else {
            // cout << area << ' ' << tempW << ' ' << tempH << '\n';
            int tempBrown = 2*(tempW + tempH) - 4;
            int tempYellow = (tempW -2) * (tempH - 2);
            if (tempBrown != brown || tempYellow != yellow) continue;
            else {
                w = tempW;
                h = tempH;
                break;
            }
        }
    }
    
    answer.push_back(w);
    answer.push_back(h);

    return answer;
}
