/*
Check if a Number is a Palindrome
Write a loop to reverse a number and then check if its a Palindrome
PALINDROME -- reverse of a number is equal to a number
function Palindrome(int n)
output
cout<<"palindrome";
cout<<"not a palindrome";
*/
#include<iostream>
using namespace std;

void Palindrome(int n)
{
    int rev=0;
    int r;
    int m=n;
    
    while(n>0){
       r=n%10;
       n/=10;
       rev=rev*10+r;
   }
    
    if(rev==m){
        std::cout<<"palindrome";
    }
    else{
        std::cout<<"not a palindrome";
    }
}
