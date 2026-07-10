//1291
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Brute 
bool isSequential(int num){
    string s=to_string(num);
    for(int i{};i<s.size()-1;++i){
        if(s[i+1]-s[i]!=1){
            return false;
        }
    }
    return true;
}

vector<int> sequentialDigits(int low, int high){
    vector<int> ans;
    for(int i{low};i<=high;++i){
        if(isSequential(i)){
            ans.push_back(i);
        }
    }
    return ans;
}

//Optimal
vector<int> sequentialDigitsOptimal(int low, int high){
    vector<int> ans;
    string s="123456789";
    for(int i{2};i<=9;++i){
        for(int j{};j+i<=9;++j){
            int num=stoi(s.substr(j,i));
            if(num>=low && num<=high){
                ans.push_back(num);
            }
        }
    }
    return ans;
}


//Another one (******)
vector<int> sequentialDigits(int low, int high) {
    queue<int> q;
    
    for (int i = 1; i <= 9; i++){
        q.push(i);
    }
    
    vector<int> ans;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if (curr >= low && curr <= high){
            ans.push_back(curr);
        }
        
        int lastDigit = curr % 10;
        if (lastDigit < 9) {
            int next = curr * 10 + (lastDigit + 1);
            if (next <= high){
                q.push(next);
            }
        }
    }

    return ans;
}
