#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, pair<int, string>> piis;

map<string, int> genres_cnt; // 장르, 총 재생횟수
vector<piis> songs; // 고유번호 : 재생횟수, 장르

bool compare(piis a, piis b){
    int pk_a = a.first;
    int played_a = a.second.first;
    string genre_a = a.second.second;
    int genre_a_played = genres_cnt[genre_a];
    
    int pk_b = b.first;
    int played_b = b.second.first;
    string genre_b = b.second.second;
    int genre_b_played = genres_cnt[genre_b];
    
    if(genre_a != genre_b) return genre_a_played > genre_b_played;
    else {
        if(played_a != played_b) return played_a > played_b;
        else return pk_a < pk_b;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for (int i=0; i<plays.size(); i++){ // 1. 많이 재생된 장르 찾기
        genres_cnt[genres[i]] += plays[i];
        pair<int, string> content = make_pair(plays[i], genres[i]);
        songs.push_back(make_pair(i, content));
    }
    sort(songs.begin(), songs.end(), compare);
    
    
    map<string, int> genres_in; // 장르, 수록 개수
    for(int i=0; i<songs.size(); i++){
        string genre = songs[i].second.second;
        int in = genres_in[genre];
        if(in >= 2) continue;
        answer.push_back(songs[i].first);
        genres_in[genre]++;
    }
    
    return answer;
}
