#include<iostream>
#include<string>
using namespace std;

int maximum69Number (int num) {
    string s = to_string(num);
    
    for(char &ch : s){
        if(ch == '6'){
            ch = '9';
            break;
        }
    }
    return stoi(s);
}

int maximum69Number (int num) {
    int temp = num;
    int pos = 0;
    int place = 1;
    
    while(temp > 0){
        int digit = temp % 10;
        
        if(digit == 6)
        pos = place;
        
        temp /= 10;
        place *= 10;
    }
    
    return num + 3 * pos;
}

