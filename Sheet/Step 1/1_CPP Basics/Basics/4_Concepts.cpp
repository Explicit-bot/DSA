/*
                ====================================================
                                    Divison By Zero
                ====================================================
if (a / 0 == 2)
a / 0 is a division by zero, which is undefined behavior in C++.

🔍 What will the compiler or runtime do?
🖥️ If a is an int:
The program will compile.
But at runtime, when it executes a / 0, it will crash.
You might get an error like:
    Floating point exception (core dumped)
🚨 Division by zero in integer arithmetic is not allowed and causes a runtime error.

✅ What About Floating-Point Division?
If you do:
    double a = 10;
    if (a / 0.0 == INFINITY)
This does not crash.

In floating-point math:
10 / 0.0 results in +∞ (infinity).
-10 / 0.0 results in -∞.
0 / 0.0 results in NaN (Not a Number).
These are part of the IEEE 754 standard for floating-point numbers.

            ====================================================
                    Increment and Decrement Operator
            ====================================================
Pre inc : ++x ->  x=x+1;    //First Increment then Operation         
Post inc : x++ ->  x=x+1;   //First operation then increment       
Pre dec : --x ->  x=x-1;    //First Decrementthen Operation   
Post dec : x--  ->  x=x-1;  //First operation then Decrement  
**(Whatever maybe the operation)
e.g.
Even for cout
  int x=5;
  cout<<++x;    //Output:5 and x becomes 6

j=2* ++i + 2* i++   
In C++, these kind of lines causes undefined behavior.
  the compiler is free to do anything:
	  •	It might do ++i first
	  •	Or i++ first
	  •	Or reuse i in an intermediate form
	  •	Or optimize in strange ways

        ====================================================
                          Overflow
        ====================================================
When the value is more than the capacity it will take the values
again from the beginning this concept is called overflow
e.g
    char y =-128;
    --y;
    std::cout << (int)y << std::endl; //-128 to 127

    char x =127;
    ++x;
    std::cout << (int)x << std::endl; //127 to -128

        ====================================================
                          Bitwise Operator
        ====================================================
These operators are performed on the bits of the data and
not as the single whole data unit
• The operations available here are
& - and
| - or
^ - xor
~ - not
<< - left shift
>> - Right Shift

• Its working 
1. and(&)
    bit1    bit2    bit1&bit2             Example   
     0       0         0                  a = 0 0 0 0 0 1 0 1 (5) 
     1       0         0                  b = 0 0 0 0 1 0 0 1 (9)
     0       1         0                a&b = 0 0 0 0 0 0 0 1 (1)
     1       1         1                        

2. or(|)
    bit1    bit2    bit1|bit2      
     0       0         0 
     1       0         1
     0       1         1 
     1       1         1 

3. xor(^)
    bit1    bit2    bit1&bit2      
     0       0         0 
     1       0         1
     0       1         1 
     1       1         0 

4. not(~)
    bit1    ~bit1
     0        1
     1        0

a & b   =   ← all 1 means 1 
a | b   =   ← 1 wherever 1 
a ^ b   =   ← 1s where a and b differ
~a      =   ← flipped all bits of a (two’s complement form) [~a = -(a + 1)]
a << n  =   ← left shift (multiply by 2^n)
b >> n  =   ← right shift (divide by 2^n)

        ====================================================
                            typedef
        ====================================================
• To give meaning full names to the variables typedef is used
• It is also used to define user define data type
• It is used for better readability of a program
Ex :
    #include <iostream>

    typedef int marks ;
    typedef int rollno ;

    int main( ) {
        marks m1, m2, m3;
        rollno r1 ,r2, r3;

    }

        ====================================================
                          Enumerated
        ====================================================
Enum is a way to give meaningful names to a fixed set of related numbers so humans can understand the code.
enum GameState {
    MENU,
    PLAYING,
    PAUSED,
    GAME_OVER
};
Would you want to read this?
    if (state == 3) {
    ???  
    }
Or this?
    if (state == GAME_OVER) {
        rip  
    }
This is where enum helps.

🧠 What actually happens
Compiler stores enums as integers
Ex :
enum days { mon , tue , wed , thu , fri , sat , sun };
            0     1     2      3      4     5     6
    
Internally:
mon → 0
tue → 1
wed → 2
thu → 3
fri → 4
sat → 5
sun → 6

Day d = wed;   // computer sees: int d = 2;
➡️ No extra memory, no extra time, zero overhead

•Here you can access the values that are assigned to it already
you cannot define your own values here.
•By default the index value assigned is 0 but you can change it if you
  want  e.g.
    enum dept { CS=2, IT , EEE=9, CIVIL };
                 2    3     9       10
*/
