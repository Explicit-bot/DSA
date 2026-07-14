#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> ans;
    for(int i{};i<words.size();++i){
        for(int j{};j<words[i].size();++j){
            if(words[i][j]==x){
                ans.push_back(i);
                break;
            }
        }
    }
    return ans;
}
