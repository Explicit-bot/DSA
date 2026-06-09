/*
1️⃣ WHAT IS INPUT / OUTPUT?
•Input  → Taking data from the user (keyboard, file, etc.)
•Output → Displaying data to the user (screen, file, etc.)
In C++, standard I/O is done using STREAMS.

2️⃣ HEADER FILE FOR I/O
    #include <iostream>
    using namespace std;
Provides:
✔ cin   → input
✔ cout  → output
✔ endl  → newline
All belong to the std namespace.

3️⃣ OUTPUT IN C++ (cout)
Syntax:
cout << data;
e.g.
    cout << "Hello World";
Output: Hello World

    cout << "Sum = " << 10;
Output: Sum = 10

    cout << "Hello" << endl;
    cout << "World";
Output: Hello
        World
    
 ***'\n' vs endl 
endl:
   ✔ Moves cursor to new line
   ✔ Flushes output buffer
   ❌ Slower
               
'\n':
✔ Moves cursor to new line
✔ Faster
✔ Preferred in CP

4️⃣ INPUT IN C++
Syntax:
cin >> variable;
e.g.    
    int x;
    cin >> x;

Taking multiple Inputs:
    int a, b;
    cin >> a >> b;
Input:
    5 10

Values:
a = 5
b = 10

5️⃣ HOW cin WORKS
✔ cin skips whitespace automatically
✔ Stops reading at:
	•	Space ' '
	•	Tab \t
	•	Newline \n
    •   '\r' (carriage return)

    string s;
    cin >> s;
Input:
    Hello World
Stored:
    s = "Hello"
❌ cin cannot read spaces in strings

6️⃣ TAKING FULL LINE INPUT 
Syntax:
    getline(cin, variable);
e.g.    
    string name;
    getline(cin, name);

Input:
    Naman Mishra

Stored:
    name = "Naman Mishra"

7️⃣ cin + getline PROBLEM 
    int age;
    string name;

    cin >> age;
    getline(cin, name);   // ❌ skipped
WHY?
✔ cin leaves '\n' in input buffer
✔ getline reads that newline immediately

SOLUTION:
    cin >> age;
    cin.ignore();         // removes leftover '\n'
    getline(cin, name);   // works correctly

8️⃣ FAST I/O 
Disable sync with C I/O:
    ios::sync_with_stdio(false);
    cin.tie(NULL);

✔ Makes cin/cout faster
✔ Required for large inputs
✔ Always place at the very start of main()
*/


#include <iostream>
using namespace std;

int main() {
    //Faster Input/Output
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    //OUTPUT USING cout   
    cout << "Hello World\n";
    cout << "Sum = " << 10 << "\n";

    //INPUT USING cin
    int x;
    cout << "\nEnter a number: ";
    cin >> x;
    cout << "You entered: " << x << "\n";

    // Multiple inputs
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "a = " << a << ", b = " << b << "\n";

    string FullName;
    cin>>FullName;      //Only until Whitespace 

    cout<<FullName;
    
    //FULL LINE INPUT USING getline
    string fullName;
    cin.ignore();   // IMPORTANT: clears leftover '\n'

    cout << "Enter full name: ";
    getline(cin, fullName);

    cout << "Full name stored: " << fullName << "\n";

    return 0;
}

/*
-----------------------------setprecision()--------------------------------------
• We can specify the number of decimal points to print in cout by using the setprecision() function.

• This function is defined in the iomanip header file, which stands for input/output manipulation.

Example: Using setprecision() For Floating-Point Numbers
        #include <iomanip>
        #include <iostream>

        using namespace std;

        int main() {
            // Creating a double type variable
            double a = 3.912348239293;

            // Creating a float type variable
            float b = 3.912348239293f;

            // Setting the precision to 12 decimal places
            cout << setprecision(13);

            // Printing the two variables
            cout << "Double Type Number  = " << a << endl;
            cout << "Float Type Number   = " << b << endl;

            //OUTPUT FORMATTING
            double pi = 3.14159;
            cout << "\nFormatted output (2 decimal places): ";
            cout << fixed << setprecision(2) << pi << "\n";

            return 0;
        }
Output:
    Double Type Number  = 3.912348239293
    Float Type Number   = 3.912348270416
    Formatted output (2 decimal places): 3.14

Note: If we specify the precision greater than the precision of the data type itself (7 for float and 15 for double), then the compiler will give us garbage values after the precision limit has been exceeded, as can be seen with the float output in example .

fixed displays floating-point numbers in the decimal format. It is similar to displaying floating-point numbers by only using cout without setprecision(), except for the fact that fixed displays numbers up to 6 decimal points.

On the other hand, only using cout displays digits according to the specific compiler (6 total digits in the case of MinGW compiler, including the digits before the decimal point).

| Without fixed                        | With fixed                       |
| ------------------------------------ | -------------------------------- |
| Precision = total significant digits | Precision = digits after decimal |
| Scientific/general format possible   | Normal decimal format            |
| 3.14159 → 3.1                        | 3.14159 → 3.14                   |

------------------------------Work with Exponential Numbers------------------------------
float and double can also be used to represent exponential numbers. For example,
    // ex = 325 X (10 ^ 25)
    double ex = 325E25;
C++ outputs exponential numbers and very large numbers in a format called the scientific format. The variable ex will be outputted in this format by default since it is a very large number.

In order to force C++ to display our floating-point numbers in the scientific format regardless of the size of the number, we use the format specifier scientific inside of cout.

Example: Fixed and Scientific Formats
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double a = 3.912348239293;
    double ex1 = 325e+2;
    float b = 3.912348239293f;
    float ex2 = 325e+2f;

    // Displaying output with fixed
    cout << "Displaying Output With fixed:" << endl;
    cout << "Double Type Number 1 = " << fixed << a << endl;
    cout << "Double Type Number 2  = " << fixed << ex1 << endl;
    cout << "Float Type Number 1   = " << fixed << b << endl;
    cout << "Float Type Number 2   = " << fixed << ex2 << endl;

    // Displaying output with scientific
    cout << "\nDisplaying Output With scientific:" << endl;
    cout << "Double Type Number 1  = " << scientific << a << endl;
    cout << "Double Type Number 2  = " << scientific << ex1 << endl;
    cout << "Float Type Number 1   = " << scientific << b << endl;
    cout << "Float Type Number 2   = " << scientific << ex2 << endl;
    return 0;
}
Output:
Displaying Output With fixed:
Double Type Number 1  = 3.912348
Double Type Number 2  = 32500.000000
Float Type Number 1   = 3.912348
Float Type Number 2   = 32500.000000

Displaying Output With scientific:
Double Type Number 1  = 3.912348e+000
Double Type Number 2  = 3.250000e+004
Float Type Number 1   = 3.912348e+000
Float Type Number 2   = 3.250000e+004
*/
