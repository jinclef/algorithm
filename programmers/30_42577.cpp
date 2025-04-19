#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, int> pii;
vector<pii> sort_with_length;

bool compare(pii a, pii b){
    return a.second > b.second;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(int i=0; i<phone_book.size(); i++){
        sort_with_length.push_back(make_pair(i, phone_book[i].length())); // idx, len
    }
    
    sort(sort_with_length.begin(), sort_with_length.end(), compare);
    
//     for (int i=0; i<sort_with_length.size(); i++){
//         cout << sort_with_length[i].first << ',' << sort_with_length[i].second << " | ";
//     }
//     cout << '\n';
    
//     for (int i=0; i<sort_with_length.size(); i++){
//         cout << phone_book[sort_with_length[i].first] << ' ';
//     }
//     cout << '\n';
//     cout << '\n';
    
    int prefix_idx = phone_book.size()-1;
    int word_idx = 0;
    while(prefix_idx > word_idx){
        string prefix = phone_book[sort_with_length[prefix_idx].first];
        string word = phone_book[sort_with_length[word_idx].first];
        
        if(prefix != word && word.substr(0, prefix.length()) == prefix){ // 접두사 발견
            answer = false;
            break;
        } else{
            word_idx++;
            if(word_idx == prefix_idx){
                prefix_idx--;
                word_idx = 0;
            }
        }
    }
    
    return answer;
}
