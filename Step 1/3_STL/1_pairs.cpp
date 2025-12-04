/*
🔥 What is pair?
A pair is a simple container in <utility> library that stores two values (possibly of different types) in one unit.

    #include <utility>  // necessary header

    pair<int, string> p1 = {101, "Messi"};

    Now, 
    p1.first = 101 & p1.second = "Messi"
    — clean, organized, and low-effort. 🎯

🏗 Ways to Create a Pair
    1. Direct Initialization
        pair<int, string> p(10, "Virat");

    2. Using {}
        pair<int, char> p = {1, 'A'};

    3. Using make_pair()
        auto p = make_pair(5, 6.9);  

    4. Nested Pairs 
        pair<int, pair<int,int>> point = {1, {2,3}};
    Access like ↓
    cout << point.first;           // 1
    cout << point.second.first;    // 2
    cout << point.second.second;   // 3

🧩 Accessing Elements
    pair<int,string> p = {7, "CR7"};

    cout << p.first;   // 7
    cout << p.second;  // CR7

Returning multiple values from function
    pair<int, int> getMinMax(vector<int>& arr){
        return { *min_element(arr.begin(), arr.end()),
                 *max_element(arr.begin(), arr.end()) };
    }

Pair Array in C++
pair<Type1, Type2> arr[size];

Examples:
    pair<int,int> p[5];                    // array of integer pairs
    pair<string,int> students[10];         // name + score
    pair<int, pair<int,int>> data[20];     // nested pair array

Initializing Pair Array
    1. Using { } list
        pair<int,int> p[] = {{1,2}, {3,4}, {5,6}};

    2. Using assignment
        p[0] = {10, 20};
        p[1].first = 15;
        p[1].second = 30;

    3. Using make_pair()
        p[2] = make_pair(25, 50);

    5. Accessing Elements
        Each element of array = one pair
        Each pair = .first and .second

cout << arr[i].first;
cout << arr[i].second;

Traversing Pair Array
    Using loop
        for(int i=0; i<n; i++)
        cout << arr[i].first << " " << arr[i].second << endl;

    Using auto (clean & modern)
        for(auto &x : arr)
        cout << x.first << " " << x.second << "\n";
*/
#include <iostream>
#include <utility>
using namespace std;

int main(){
    pair<int,int> arr[4] = {{4,1}, {2,3}, {1,5}, {2,2}};

    // Sort based on first
    sort(arr, arr+4);

    cout << "Sorted Pairs:\n";
    for(auto &p : arr)
        cout << p.first << " " << p.second << "\n";

    return 0;
}
