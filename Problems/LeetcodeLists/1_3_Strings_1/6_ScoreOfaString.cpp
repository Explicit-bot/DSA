#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int scoreOfString(string s) {
    int n=s.size();
    int sum{};
    for(int i{1};i<n;++i){
        sum+=abs(s[i]-s[i-1]);
    }
    return sum;
}
