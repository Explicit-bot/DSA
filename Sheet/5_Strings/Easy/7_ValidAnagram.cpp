#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isAnagramBrute(string s,string t){
    if(s.length()!=t.length()){
        return false;
    }
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    for(int i{};i<s.length();++i){
        if(s[i]!=t[i]){
            return false;
        }
    }
    return true;
}

bool isAnagramOptimal(string s,string t){
    if(s.length()!=t.length()){
        return false;
    }
    int arr[26]={};
    for(auto x:s){
        ++arr[x-'a'];
    }
    for(auto x:t){
        --arr[x-'a'];
    }
    for(auto x:arr){
        if(x!=0){
            return false;
        }
    }

    return true;
}


/*
What if the input strings contain Unicode characters? How would you adapt your solution to handle such a case?
The frequency array approach using a fixed-size array of 26 characters only works when the input consists of lowercase English letters (`a-z`). Unicode contains a much larger set of characters, including characters from different languages and emojis, so a fixed-size array is no longer practical.

To handle Unicode characters, replace the frequency array with a hash map such as `unordered_map`. 
This approach maintains a time complexity of `O(n)` and a space complexity of `O(k)`, where `k` is the number of distinct characters.
In C++, for true Unicode support, I would also ensure that I am working with Unicode code points rather than raw UTF-8 bytes, for example by using `std::u32string` or proper UTF-8 decoding before counting frequencies.

*/
