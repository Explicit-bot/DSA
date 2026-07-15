#include<iostream>
#include<string>
using namespace std;

string interpret(string command) {
    int n=command.size();
    int i{};
    string ans;
    while(i<n){
        if(command[i]=='G'){
            ans.push_back('G');
            ++i;
        }
        else if(command[i+1]==')'){
            ans.push_back('o');
            i+=2;
        }
        else{
            ans.push_back('a');
            ans.push_back('l');
            i+=4;
        }
    }
    return ans;
}
