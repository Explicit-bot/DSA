#include<iostream>
#include<string>
#include<vector>
using namespace std;

string SortByfreqBrute(string s){
    unordered_map<char,int> freq;
    for(auto& x:s){
        ++freq[x];
    }

    string ans;
    while(!freq.empty()){
        int maxcnt{-1};
        char maxch;
        for(auto it:freq){
            if(it.second>maxcnt){
                maxcnt=it.second;
                maxch=it.first;
            }
        }

        ans+=string(maxcnt,maxch);
        freq.erase(maxch);
    }
    return ans;
}


string SortByfreqBetter(string s){
    unordered_map<char,int> freq;
    for(auto& x:s){
        ++freq[x];
    }
    vector<pair<char,int>> vec(freq.begin(), freq.end());

    sort(vec.begin(),vec.end(), 
                                [](auto &a, auto &b){
                                    return a.second > b.second;
                                }
    );

    string ans;
    for(auto x:vec){
        ans+=string(x.second,x.first);
    }
    return ans;
}

string SortByfreqOptimal(string s){
    unordered_map<char,int> freq;
    for(auto& x:s){
        ++freq[x];
    }

    vector<vector<char>> bucket(s.size()+1);
    for(auto x:freq){
        bucket[x.second].push_back(x.first);
    }
    string ans;
    for(int i=s.size();i>=1;--i){
        for(auto& x:bucket[i]){
            ans+=string(i,x);
        }
    }

    return ans;
}
