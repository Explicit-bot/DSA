//504
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string convertToBase7(int num) {
    if(num==0){
        return "0";
    }
    int sign{1};
    if(num<0){
        sign=-1;
        num=abs(num);
    }
    string s="";
    while(num){
        s+=num%7+'0';
        num/=7;
    }
    if(sign==-1){
        s+='-';
    }
    reverse(s.begin(),s.end());
    return s;
}
