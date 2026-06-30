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

        if(target==goal){
            return true;
        }
    }
    return false;
}

bool rotateStringBrute(string s,string goal){
    if(s.size()!=goal.size()){
        return false;
    }

    string doubled=s+s;

    return doubled.find(goal)!=string::npos;
}

