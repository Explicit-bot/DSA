/*
                Program for count vowels consonant and words
Method-1************************************************
# include<iostream>
using namespace std;
    
int main(){
    string str;
    cout<<"Enter your String:"<<flush;
    getline(cin,str);

	int vowels=0,consonant=0,space=0;
	for(int i=0;str[i]=!'\0';i++){
		if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
		      vowels++;
        }
		else if(str[i]==' '){
		    space++;
        }
		else{
		    consonant++;
        }
	}
	cout<<"vowels "<<vowels<<endl;
	cout<<"consonant "<<consonant<<endl;
	cout<<"words "<<space++<<endl;
	return 0;
}

Method-2************************************************
#include <iostream>
#include <cctype>

int main() {
    std::string str = "Hello 123! Welcome\tto 2025.";

    int letters = 0, digits = 0, spaces = 0;

    for (char ch : str) {
        if (std::isalpha(ch)) ++letters;
        else if (std::isdigit(ch)) ++digits;
        else if (std::isspace(ch)) ++spaces;
    }

    std::cout << "Letters: " << letters << "\nDigits: " << digits << "\nSpaces: " << spaces << '\n';
}
*/

/*
🔹 <cctype> Functions Overview
These functions work with char and are used for character classification or transformation.

1. isalnum(char c)
Checks: Is c alphanumeric? (A–Z, a–z, 0–9)
Returns: true if letter or digit
isalnum('A') → true
isalnum('1') → true
isalnum('$') → false

2. isalpha(char c)
Checks: Is c an alphabet? (A–Z, a–z)
isalpha('B') → true
isalpha('4') → false

3. isdigit(char c)
Checks: Is c a digit? (0–9)
isdigit('8') → true
isdigit('b') → false

4. islower(char c)
Checks: Is c a lowercase letter? (a–z)
islower('a') → true
islower('A') → false

5. isupper(char c)
Checks: Is c an uppercase letter? (A–Z)
isupper('Z') → true
isupper('z') → false

6. isspace(char c)
Checks: Is c a whitespace character? Includes: ' ', '\t', '\n', '\v', '\f', '\r'
isspace(' ') → true
isspace('\n') → true
isspace('A') → false

7. ispunct(char c)
Checks: Is c a punctuation character? (e.g., !, @, #, {, etc.)
ispunct('!') → true
ispunct('A') → false

8. iscntrl(char c)
Checks: Is c a control character? (e.g., \n, \t, ASCII 0–31 and 127)
iscntrl('\n') → true
iscntrl('A') → false

9. isprint(char c)
Checks: Is c a printable character (including space)?
isprint('A') → true
isprint(' ') → true
isprint('\n') → false

10. isgraph(char c)
Checks: Is c printable and not a space?
isgraph('A') → true
isgraph(' ') → false

11. tolower(char c)
Converts: Uppercase to lowercase if applicable.
    tolower('A') → 'a'
    tolower('a') → 'a' (no change)

12. toupper(char c)
Converts: Lowercase to uppercase if applicable.
    toupper('b') → 'B'
    toupper('B') → 'B' (no change)

🔹 Example Program:
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char c = 'A';

    cout << "isalpha: " << isalpha(c) << endl;
    cout << "isdigit: " << isdigit(c) << endl;
    cout << "tolower: " << (char)tolower(c) << endl;
}
*/
