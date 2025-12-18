/*
🚨 Problem: Integer Overflow
    You’re storing the factorial result in an int:
        int fact{1};  // ❌ Too small for large factorials
    But:
    int range (on most systems):
	-2147483648 to 2147483647
    
    😱 Size of 74!:
	•	74! ≈ 3.32 × 10^109
	•	It has over 100 digits!
    Which means:
    int (or even long long) can’t hold that big a number.
    So the result overflows and becomes garbage or zero.

    ✅ Solutions:
    🔹 1. Use unsigned long long (up to 20! safely)
            unsigned long long fact = 1;
        But even this overflows around 21!

    🔹 2. Use Big Integer Library
        To go beyond 20–30!, you’ll need a big integer type, like:
        ✅ In C++:
        •Use __int128 (GCC/Clang only) - upto 34!
	    •Use libraries like:
	        Boost::multiprecision
	    •Write your own with std::vector<int> and manual multiplication
*/
#include<iostream>

int main(){
    int n{};
    unsigned long long int fact{1};
    std::cout<<"Enter no. whose factorial is req.:";
    std::cin>>n;
    /*
	•i starts at 1.
	•fact starts at 1 (since factorial is a product).
    */
    for( int i{1};i<=n;++i) 
    {
        fact*=i;
    }
    std::cout<< n<<"! ="<<fact<<std::endl;

    return 0;
}
