#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n;
int placeSum[26];
int matchVal[26];

struct cmp{
    bool operator()(pii a, pii b){
        return a.second < b.second;    
    }
};

string havetoSum[11];

priority_queue<pii, vector<pii>, cmp> maxLetter; // idx, count

int pow(int x, int y){
    // x를 y번 곱한다.
    int temp = 1;
    while(y>0){
        temp *=x;
        y--;
    }
    return temp;
}

int main(){
    cin >> n;

    for (int i=0;i<n;i++){
        string nums;
        cin >> nums;
        havetoSum[i] = nums;
        for (int j=0; j<nums.length(); j++){
            int idx = nums[j]-'A';
            int place = nums.length() - j;
            
            placeSum[idx] += pow(10, place-1);
        }
    }

    for (int i=0;i<26;i++){
        maxLetter.push(pii(i, placeSum[i])); // sum 이 큰 순으로 정렬된다.
    }

    // 문자-정수 대응시키기
    int val = 9;
    while(maxLetter.size()>0){
        pii top = maxLetter.top(); maxLetter.pop();
        matchVal[top.first] = val;
        // cout << a << ' ' << matchVal[top.first] << '\n';
        val--;
    }

    // sum
    int sum = 0;
    for (int i=0;i<n;i++){
        string english = havetoSum[i];
        for (int j=0;j<english.length();j++){
            // cout << matchVal[english[j]-'A'] * pow(10,(english.length()-j-1)) << '\n';
            sum += matchVal[english[j]-'A'] * pow(10,(english.length()-j-1));
        }
    }

    cout << sum << '\n';

    return 0;
}