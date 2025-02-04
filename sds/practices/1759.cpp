#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L,C; //L: 알파벳 소문자 개수. C: 암호 알파벳 후보 개수
char pwds[27]; // 26+1
char aeiou[5] = {'a', 'e', 'i', 'o', 'u'};
char etcs[22] = {'b', 'c', 'd', 'f', 'g', 'h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
vector<char> myaeiou;
vector<char> myetc;

bool selectedA[5];
int selectedZ[22] = {0, }; // 0: 방문전 -1: 방문완료 1: 방문중

bool isAeiou(char k){
    for (int i=0;i<5; ++i){
        if (k == aeiou[i]) return true;
    }
    return false;
}

bool hasAeiou(char k){
    for (int i=0;i<myaeiou.size(); ++i){
        if (k == myaeiou[i]) return true;
    }
    return false;
}

bool hasEtc(char k){
    for (int i=0; i<myetc.size(); ++i){
        if(k==myetc[i]) return true;
    }
    return false;
}

void doneVisit(){
    for (int i=0;i<22;++i){
        if(selectedZ[i]==1) selectedZ[i]=-1;
    }
}

void printVisit(auto* arr, int size){
    for (int i=0;i<size;++i){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void combinationEtcs(int len, int count){ //TODO: 얘도 백트레킹으로 뽑기
    int idx=0;
    bool flag = false;

    while(count <= len){
        // cout << count << ' ' << len << '\n';
        printVisit(selectedZ, 22);
        if(count == len) {
            flag = true;
            break;
        }
        // cout << idx << '-' ;
        // printVisit();
        if(hasEtc(etcs[idx]) && selectedZ[idx] == 0){
            selectedZ[idx] = 1;
            count++;
        }
        idx++;
    }
    return;
}

void printCanPwd(){
    vector<char> total;
    for(int i=0;i<5;++i){
        if(selectedA[i]) total.push_back(aeiou[i]);
    }
    for(int i=0;i<21;++i){
        if(selectedZ[i]==1) total.push_back(etcs[i]);
    }

    sort(total.begin(), total.end());
    // do{
    //     for(auto it=total.begin();it!=total.end();++it)
    //         cout << *it;
    //     cout << '\n';
    // } while(next_permutation(total.begin(), total.end()));

    // 무조건 오름차순
    for(auto it=total.begin();it!=total.end();++it)
        cout << *it;
    cout << '\n';
    doneVisit();
}

void makePwd(int idx, int cnt, int aeiouCnt, int etcCnt){
    printVisit(selectedA, 5);
    cout << "makepwd: " << idx << " " << cnt << " " << aeiouCnt << ' '<<etcCnt << '\n';
    if(cnt == aeiouCnt) {
        while(true){ // left unvisitedCombinations
            combinationEtcs(etcCnt, 0); // 자음 조합 찾기
            printCanPwd();
        }
        doneVisit();
        return;
    }
    if(idx>=5) {
        // cout << "oor. return makepwd: " << idx << " " << cnt << " " << aeiouCnt << ' '<<etcCnt << '\n';
        return;
    }

    if(hasAeiou(aeiou[idx])) {
        selectedA[idx] = true;
        makePwd(idx+1, cnt+1, aeiouCnt, etcCnt);
        selectedA[idx] = false;
    }
    makePwd(idx+1, cnt, aeiouCnt, etcCnt);

    // cout << "not. return makepwd: " << idx << " " << cnt << " " << aeiouCnt << ' '<<etcCnt << '\n';
    return;
}

int main(){
    cin >> L >> C; // L 은 무조건 3 이상.
    for (int i=0;i<C;++i) {
        cin >> pwds[i];
        if (isAeiou(pwds[i])) myaeiou.push_back(pwds[i]);
        else myetc.push_back(pwds[i]);
    }

    sort(myaeiou.begin(), myaeiou.end());
    sort(myetc.begin(), myetc.end());

    // 모음 1개 이상, 자음 2개 이상 조건 만족하도록 찾기.
    if(myaeiou.size() < 1 || myetc.size() < 2) return 0; // 없음

    // 모음 최대에서 while문을 돌고 싶은데, 그러려면 우선 자음 최소 개수를 알아야 함.
    int unb_etcs = min((int)myetc.size(), 2); //under bound
    int upb_aeious = L-2;                     //upper bound

    while(upb_aeious < (int)myaeiou.size()){ // 개수 모자라서 그만큼 못해줌.
        upb_aeious--;
    }
     
    int aeious = upb_aeious;
    int tryEtcs = L - aeious; // 초기값 초기화 완료.

    // 모음 개수 최대 -> 최소 로 while 문 돌면서 가능한 단어 출력하기.
    while(aeious>=1){
        tryEtcs = L-aeious;
        if(tryEtcs<unb_etcs) break;

        cout<< "let's loop " << aeious << ' ' << tryEtcs << '\n';
        makePwd(0, 0, aeious, tryEtcs);
        cout << "exit loop\n";
        aeious--;
    }
    
    return 0;
}