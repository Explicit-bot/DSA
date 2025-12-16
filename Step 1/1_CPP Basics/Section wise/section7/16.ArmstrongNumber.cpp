/*
💡 What is an Armstrong Number?
A number is an Armstrong number if the sum of its digits each raised to the power of the number of digits is equal to the number itself.
🔹 Formula:
For a number with n digits:
Armstrong <==> d_1^n + d_2^n +.......+ d_n^n = number
✅ Examples:
🟢 3-digit Armstrong Numbers:
🔸 153:
	•	Digits: 1, 5, 3
	•	1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153 ✅
🔸 370:
	•	3^3 + 7^3 + 0^3 = 27 + 343 + 0 = 370 ✅
🔸 9474 (4-digit):
	•	9^4 + 4^4 + 7^4 + 4^4 = 6561 + 256 + 2401 + 256 = 9474 ✅
❌ Non-Armstrong Example:
🔸 123:
	•	1^3 + 2^3 + 3^3 = 1 + 8 + 27 = 36 \ne 123 ❌
*/

#include <iostream>
#include <cmath>

int main(){
    int num{};
    int sum{};

    std::cout<<"Enter no.:"<<std::flush;
    std::cin>>num;

//counting no. of digits
    int digits{};
    int temp=num;
    while(temp!=0){
     ++digits;
        temp/=10;
    }
//sum of powered no.s
    temp=num;
    while(temp!=0){
        int digit=temp%10;
        sum+=std::pow(digit,digits);
        temp/=10;
    }
    if(sum==num){
        std::cout<<num<<" is an armstrong number.\n";
    }
    else{
        std::cout<<num<<" is not an armstrong number.\n";
    }
}
