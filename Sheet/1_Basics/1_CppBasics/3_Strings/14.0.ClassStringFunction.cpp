/*
You can use this as a reference or checklist while learning or documenting.

🔹 0. Constructors (Object Creation)
std::string();                              // default constructor
std::string(const std::string& str);        // copy constructor
std::string(std::string&& str);             // move constructor
std::string(const char* s);                 // from C-string
std::string(const char* s, size_t n);       // from char* and length
std::string(size_t n, char c);              // n copies of char
std::string(std::initializer_list<char>);   // from init list
template<class InputIterator>
std::string(InputIterator first, InputIterator last);  // from range

🔹 1. Capacity Functions
Function	                Description
✅size() / length()	        Returns current length of string
✅capacity()	                Returns internal storage capacity
✅max_size()	                Returns maximum size string can reach
✅resize(n)	                Resizes string to n characters
✅resize(n, c)	            Resize and fill new space with c
✅reserve(n)	                Requests capacity at least n
✅shrink_to_fit()	            Reduces capacity to fit size
✅empty()                 	Checks if string is empty
✅clear()	                    Removes all characters

🔹 2. Element Access
Function	                        Description
✅operator[](pos)	                    Direct access (no bounds check)
✅at(pos)	                            Access with bounds checking
✅front()	                            First character
✅back()	                            Last character
✅data()	                            Returns internal character array 
                                    (non-null terminated in C++11, null in C++17+)
✅c_str()	                            Returns null-terminated character array

🔹 3. Modifiers
Function	                Description
✅assign(...)	                Assigns new value to string
✅append(...) / operator+=	Appends string or characters
✅insert(pos, ...)	        Inserts at pos
✅erase(pos, len)	            Erases len chars from pos
✅replace(pos, len, str)	    Replaces substring
✅push_back(char)	            Appends character
✅pop_back()	                Removes last character
✅swap(str)	                Swaps contents with str

🔹 4. String Operations
Function	                Description
✅compare(str)	            Compares strings (returns int)
✅substr(pos, len)	        Returns substring
✅copy(dest, len, pos)	    Copies substring into array
✅find(str, pos)	            Finds substring from position
✅rfind(str, pos)	            Finds last occurrence
✅find_first_of(str, pos)	    Finds first char from set
✅find_last_of(str, pos)	    Finds last char from set
✅find_first_not_of(str)	    First char not in str
✅find_last_not_of(str)	    Last char not in str
starts_with(str)	        Checks if starts with str (C++20)
ends_with(str)	            Checks if ends with str (C++20)
contains(str)	            Checks if contains str (C++23)

🔹 5. Iterators
Iterator Function	        Description
✅begin() / end()	            Forward iterators
✅cbegin() / cend()	        Const forward iterators
✅rbegin() / rend()	        Reverse iterators
✅crbegin() / crend()	        Const reverse iterators

🔹 6. Operator Overloads
Operator	    Description
✅+	            Concatenation
✅+=	            Append
✅==, !=	        Equality/Inequality
✅<, >, <=, >=	Lexical comparison
✅[]	            Character access
✅<<, >>	        Stream insertion/extraction

🔹 7. Non-Member String Functions
These are utility functions that work with std::string:
    std::getline(std::istream&, std::string&);
    std::swap(std::string&, std::string&);
    std::to_string(int/double/float/long/etc.);

*/

