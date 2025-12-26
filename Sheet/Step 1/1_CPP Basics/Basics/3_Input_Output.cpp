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

8️⃣ OUTPUT FORMATTING BASICS
    int a = 5;
    cout << "Value of a is " << a;

// Fixed decimal output
    cout << fixed << setprecision(2) << 3.14159;
Output:
    3.14
Requires:
    #include <iomanip>

9️⃣ FAST I/O 
Disable sync with C I/O:
    ios::sync_with_stdio(false);
    cin.tie(NULL);

✔ Makes cin/cout faster
✔ Required for large inputs
✔ Always place at the very start of main()
*/


#include <iostream>
#include <iomanip>      // for setprecision
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

    
    //OUTPUT FORMATTING
    double pi = 3.14159;
    cout << "\nFormatted output (2 decimal places): ";
    cout << fixed << setprecision(2) << pi << "\n";

    return 0;
}
