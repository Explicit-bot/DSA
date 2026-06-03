/* *********************
🔷 strtol in C++ — String to Long Conversion
✅ Purpose
Converts a C-style string (const char*) to a long int, with optional base detection and end-pointer tracking. Safe, flexible alternative to atoi.

🔹 Syntax
    #include <cstdlib>  // or <stdlib.h>

    long strtol(const char* str, char** endptr, int base);

🔹 Parameters
Parameter	        Type	        Description
str	                const char*	    Pointer to a C-string 
                                    (must be null-terminated)
endptr	            char**	        Pointer to receive the first
                                    character not used in conversion
base	            int	            Numerical base 
                                (2–36, or 0 for auto-detect from prefix)

🔹 Return Value
Condition	                Return Value
Valid integer	            The parsed long
No digits found	            0, endptr == str
Overflow / underflow	    LONG_MAX / LONG_MIN, sets errno = ERANGE

🔹 Example Usage (C++ Style)
    #include <iostream>
    #include <cstdlib>
    #include <cerrno>  // for errno

    int main() {
        const char* str = "  0x2Fabc";
        char* end;
    
        errno = 0;
        long value = strtol(str, &end, 0);  // base 0: auto-detect

        std::cout << "Parsed value: " << value << "\n";
        std::cout << "Remaining: " << end << "\n";

        if (errno == ERANGE) std::cout << "Overflow occurred.\n";
    }

🔹 Base Auto-Detection (when base = 0)
Input Prefix	    Base Used	        Example	            Result
None	            10	                "123"	            123
0	                8	                "075"	            61
0x/0X	            16	                "0x1A"	            26

🔹 Internals (How It Works)
Skips leading whitespace.
Handles optional + or -.
Parses characters valid in specified base.
Stops at first invalid character.
Updates endptr to point to the rest of the string.

🔹 Edge Cases
Input	                Output Value	        Notes
" -45xyz"	            -45	                    endptr -> "xyz"
"0xF"	                15	                    base auto-detected (hex)
"089"	                0	                    Invalid digit for octal
""	                    0	                    No digits found
"9999999999999999999"	LONG_MAX	            Overflow; errno = ERANGE

🔹 Usage in Competitive Programming
✅ Useful when:
Custom tokenizing/parsing input.
Reading integers from fgets() buffer.
Validating or rejecting malformed input.
🚫 Avoid when using std::cin, scanf, or std::stringstream, which are cleaner for simple inputs.

🔷 strtof in C++ — String to Float Conversion
✅ Purpose
Converts a C-string to a floating-point number (float). Supports scientific notation, whitespace, signs, etc.

🔹 Syntax
    #include <cstdlib>

    float strtof(const char* str, char** endptr);
🔹 Parameters
Parameter	    Type	            Description
str	            const char*	        Input C-string
endptr	        char**	            Pointer to remainder of string

🔹 Return Value
Case	                Output
Valid float	            Parsed value (float)
No number	            0.0, endptr == str
Overflow	            HUGE_VALF, errno = ERANGE

🔹 Example Usage
    #include <iostream>
    #include <cstdlib>

    int main() {
        const char* input = "-3.14159xyz";
        char* end;

        float f = strtof(input, &end);

        std::cout << "Parsed float: " << f << "\n";      // -3.14159
        std::cout << "Remaining: " << end << "\n";       // "xyz"
    }

🔹 Formats It Supports
Input	    Output
"3.14"	    3.14f
"-0.001"	-0.001f
"1.2e3"	    1200.0f
"abc"	    0.0f

🔹 When to Use in C++
✅ Use strtof when:
Parsing floats from raw buffers.
You want tight control over conversion.
Avoiding exceptions for performance.

🚫 Avoid if:
Using std::string or stream-based input.
You want higher precision → use strtod() instead.

🔹 Summary (Cheat Sheet)
Function   Parses  Returns	Error Handling	Base  Endptr Support	C++ Preferred?
strtol	   int	   long	    errno	        ✅	 ✅ Yes	           Yes 
                                                                (for raw parsing)
strtof	   float   float	errno	        ❌	 ✅ Yes	           Yes 
                                                                    (low-level use)
std::stoi  int	   int	    Exception	    ✅	 ✅	               ✅ (safer)
std::stof  float   float	Exception	    ❌	 ✅	               ✅ (modern code)

🧠 Final Tips
Prefer std::stoi/stof for safe, modern C++.
Use strtol/strtof when working with:
C APIs, char* buffers
Performance-critical code (avoids exceptions)
Manual parsing or custom tokenizers
Always check errno and endptr for reliable error handling.
*/

#include <iostream>
#include <cstdlib>  // for strtol, strtof
#include <cerrno>   // for errno
#include <climits>  // for LONG_MAX, LONG_MIN
#include <cfloat>   // for HUGE_VALF

int main() {
    const char* input = "  -1234abc56.78xyz";

    // --- Step 1: Parse integer using strtol ---
    char* intEnd;
    errno = 0;  // reset errno
    long intValue = std::strtol(input, &intEnd, 10);

    if (errno == ERANGE) {
        std::cerr << "Integer overflow or underflow!\n";
    }

    std::cout << "Parsed integer: " << intValue << "\n";
    std::cout << "Remaining after int: \"" << intEnd << "\"\n\n";

    // --- Step 2: Parse float from the remaining part using strtof ---
    char* floatEnd;
    errno = 0;  // reset errno
    float floatValue = std::strtof(intEnd, &floatEnd);

    if (errno == ERANGE) {
        std::cerr << "Float overflow or underflow!\n";
    }

    std::cout << "Parsed float: " << floatValue << "\n";
    std::cout << "Remaining after float: \"" << floatEnd << "\"\n";

    return 0;
}
//Sample output
/*
Parsed integer: -1234
Remaining after int: "abc56.78xyz"

Parsed float: 56.78
Remaining after float: "xyz"

*/
