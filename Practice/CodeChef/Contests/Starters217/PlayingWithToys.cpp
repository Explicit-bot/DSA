/*
====================================================
🧸 Playing with Toys
====================================================

Chef got N toys for his birthday.

Every day, if he has at least one toy, he plays with
one specific toy for that day.

Unfortunately, Chef is very careless and will
inevitably break that toy by the end of the day.
When he does break it, he does not play with a new
toy but just waits for the next day.

After M days, how many toys will Chef be left with?

----------------------------------------------------
Input Format
----------------------------------------------------
The first and only line of each test case contains
2 integers:
N and M

----------------------------------------------------
Output Format
----------------------------------------------------
Print the number of toys left with Chef after M days.

----------------------------------------------------
Constraints
----------------------------------------------------
1 ≤ N, M ≤ 10
====================================================

*/

#include <iostream>
using namespace std;

int main() {
    int N{},M{};
    
    cin>>N>>M;
    
    if(N>M){
        cout<<N-M;
    }

    else{
        cout<<0;
    }
    
    return 0;
}
