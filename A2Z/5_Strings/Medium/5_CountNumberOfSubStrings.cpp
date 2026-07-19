#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int countSubstringsBrute(string s, int k) {
    int n = s.size();
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        unordered_set<char> st;

        for (int j = i; j < n; ++j) {
            st.insert(s[j]);
            if (st.size() == k)
                ans++;

            else if (st.size() > k)
                break;
        }
    }

    return ans;
}

int atMostKdistinct(string s, int k){
    if(k<0){
        return 0;
    }

    int left{};
    int res{};
    unordered_map<char,int> freq;
    for(int right{};right<s.size();++right){
        freq[s[right]]++;
        while(freq.size()>k){
            freq[s[left]]--;
            if(freq[s[left]]==0){
                freq.erase(s[left]);
            }
            ++left;
        }
        res+=right-left+1;
    }
    return res;
}

int countSubstringsOptimal(string s, int k){
    return atMostKdistinct(s,k)-atMostKdistinct(s,k-1);
}


/*
Pattern to Remember
Whenever you see:
Exactly k distinct elements
Exactly k odd numbers
Exactly k zeros
Exactly k occurrences of some property

think of this transformation:
Exactly(k)=AtMost(k)- AtMost(k-1)
This is one of the most frequently used sliding window patterns in coding interviews.


# Why do we erase a character when its frequency becomes 0?

When using a frequency map in Sliding Window problems, we often use:

    freq.size()

to represent the number of distinct characters in the current window.

However, `unordered_map::size()` counts the number of keys, NOT the sum of their frequencies.

Example:

Window = "abc"

freq = {
    'a' : 1,
    'b' : 1,
    'c' : 1
}

freq.size() = 3

--------------------------------------------------

Now remove 'a' from the window:

freq['a']--;

freq becomes:

{
    'a' : 0,
    'b' : 1,
    'c' : 1
}

Although 'a' is no longer in the window, it is still a key in the map.

freq.size() = 3 ❌
Actual distinct characters = 2

--------------------------------------------------

To fix this:

if (freq[ch] == 0)
    freq.erase(ch);

Now the map becomes:

{
    'b' : 1,
    'c' : 1
}

freq.size() = 2 ✅

--------------------------------------------------

Rule to Remember

Whenever you use:

    freq.size()

to count distinct elements, always erase a key when its frequency becomes 0.

Pattern:

freq[ch]--;

if (freq[ch] == 0)
    freq.erase(ch);

--------------------------------------------------

Key Point

unordered_map::size() = Number of keys
NOT
Sum of frequencies

A key with frequency 0 is still counted until it is erased.
*/

