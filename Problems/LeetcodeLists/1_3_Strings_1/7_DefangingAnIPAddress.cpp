#include<iostream>
#include<string>
using namespace std;

string defangIPaddrNoSpace(string address) {
    for(int i{};i<address.size();++i){
        if(address[i]=='.'){
            address.replace(i,1,"[.]");
            i+=2;
        }
    }
    return address;
}

string defangIPaddr(string address) {
    string ans;
    
    for(char ch : address) {
        if(ch == '.'){
            ans += "[.]";
        }
        else{
            ans += ch;
        }
    }
    return ans;
}
