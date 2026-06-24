#include<iostream>
#include<string>
using namespace std;

bool checkIfPangram(string sentence) {
    char hash[26]={};
    for(auto x:sentence){
        ++hash[x-'a'];
    }
        
    for(auto x:hash){
        if(x==0){
            return false;
        }
    }
    return true;
}

//check the below two
bool checkIfPangram(string sentence) {
    int mask = 0;

    for(char ch : sentence)
        mask |= (1 << (ch-'a'));

    return mask == (1<<26)-1;
}
    
bool checkIfPangram(string sentence) {
    bool seen[26] = {};
    int cnt = 0;

    for(char ch : sentence) {
        if(!seen[ch-'a']) {
            seen[ch-'a'] = true;
            cnt++;

            if(cnt == 26)
                return true;
        }
    }

    return false;
}
