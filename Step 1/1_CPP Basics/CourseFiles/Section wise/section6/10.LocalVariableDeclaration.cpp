/*
✅ Block-scoped variable declaration
Also commonly known as:
📘 Local variable declaration

🔍 Definition:
A block-scoped or local variable is a variable declared inside a pair of braces {}, such as within:
	•	A function
	•	An if, else, for, or while block
	•	Any arbitrary {} block
It is created when the block is entered and destroyed when the block ends.

🔁 Examples:

🧱 1. Inside if block:
    if (x > 0) {
        int temp = x;   // Block-scoped variable
        cout << temp;
    }
temp is accessible only inside the if block.

⚙️ 2. Inside a function:
    void myFunc() {
    int local = 5;  // Local to myFunc
    }
local exists only within the myFunc() function.

🔁 3. Inside a loop:
    for (int i = 0; i < 5; i++) {
        int square = i * i;  // Block-scoped inside loop
        cout << square;
    }
square is re-declared fresh on every iteration.

🧠 Summary:
	•	✅ Declaration inside any {} is a block-scope or local variable declaration.
	•	📍 Variable lifetime = duration of the block.
	•	📦 Stored on the stack.
	•	🔒 Not accessible outside that block.
*/
#include <iostream>
int main(){
    
    int a=10,b=5;
    
    if(true){
        int c=a+b;
        std::cout<<c<<std::endl;
    }

//empty block declaration
    {
    int d=a-b;
    if(true){
        std::cout<<d<<std::endl;
    }
    }
    //d=0;    can't be accessed here
//declaration in condition
    if(int e=a*b){
        std::cout<<e<<std::endl;
    }
}
