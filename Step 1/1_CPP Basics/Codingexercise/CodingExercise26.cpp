/*
Check if a number is Perfect Number
Write a loop to check if a number is perfect number
PERFECT NUMBER - sum of the factors of number is double the number
function Perfect(int n)
output
cout<<"perfect"
cout<<"not perfect"
*/

#include<iostream>

void Perfect(int n)
{
    int sum=0;
    int i{1};
    
    while(i<=n){
        if (n%i==0){
            sum+=i;
        }
        ++i;
    /*
    Your code took too long to execute.
    Review the logic in your code might cause it and try again.
    
    this error comes in Udemy or online compilers when you forget to add ++i at this point it may happen due to any other reason to but i am writing wrt this line only now.
    }
    */
    if(sum==2*n){
        std::cout<<"perfect";
    }
    else{
        std::cout<<"not perfect";
    }
}
