//202
#include<iostream>
#include<unordered_set>
using namespace std;


//Helper Function
int squareSum(int n) {
    int sum{};
    while(n){
        int ld=n%10;
        sum+=ld*ld;
        n/=10;
    }
    return sum;
}

//Brute
bool isHappy(int n) {
    unordered_set<int> seen;

    while(n!=1){
        if(seen.count(n)){
            return false;
        }
        seen.insert(n);
        n=squareSum(n);
    }
    return true;
}

//Optimal (****)
bool isHappy(int n) {
    int slow{n};
    int fast{n};
    
    do {
        slow = squareSum(slow);
        fast = squareSum(squareSum(fast));
    } while (slow != fast);
    
    return slow == 1;
}

