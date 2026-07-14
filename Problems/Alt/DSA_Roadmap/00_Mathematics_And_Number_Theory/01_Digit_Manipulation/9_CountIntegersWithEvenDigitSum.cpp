//2180
#include<iostream>
using namespace std;

int countEvenBrute(int num) {
    int cnt = 0;
    
    for (int i{1};i <= num;++i) {
        int x{i};
        int sum{};
        
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        
        if (sum % 2 == 0)
        cnt++;
    }
    
    return cnt;
}

int countEven(int num) {
    int sum{};
    int temp{num};
    
    while(temp){
        sum+=temp%10;
        temp/=10;
    }
    return (num-(sum&1))/2;
}


/*
The parity of the digit sum alternates frequently:
Odd, Even, Odd, Even, Odd, Even ...

Therefore, among numbers from `1` to `num`:
* roughly half have an even digit sum
* roughly half have an odd digit sum

So we start with:
ans = num / 2;

Now we only need to decide whether `num` itself belongs to the even group or the odd group.

Compute: digitSum(num)
### If digitSum(num) is even `num` belongs to the even group.
Example:
num = 24
digitSum(24) = 6 (even)
Answer = 24 / 2 = 12

### If digitSum(num) is odd `num` belongs to the odd group, so we must exclude it.
Example:
num = 30
digitSum(30) = 3 (odd)
Answer = (30 - 1) / 2
       = 14

Therefore:
answer = (num - (digitSum(num) & 1)) / 2;
*/
