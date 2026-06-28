#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool rotateStringBrute(string s, string goal){
    if(s.size()!=goal.size()){
        return false;
    }
    for(int i{};i<s.size();++i){
        string target=s.substr(i)+s.substr(0,i);

    }
}
