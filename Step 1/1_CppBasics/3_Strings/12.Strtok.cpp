/*. *********************
🔷 What is strtok?
strtok is a function that helps you split a sentence (string) into words or tokens based on symbols like spaces, commas, or other characters.

Imagine you have this sentence:
"I,am,learning,C++"

You want to split this into:
"I"
"am"
"learning"
"C++"

strtok can do this for you!

🔹 Simple Steps to Use strtok
Give it a string (C-style char array) and a delimiter (e.g., ",", " ", etc.).
It gives you the first word (token).
Then call it again with nullptr to get the next word.
Repeat until it returns nullptr.

✅ Simple Program with Explanation
*/
#include <iostream>
#include <cstring>  // for strtok

int main() {
    // Step 1: Your input string (must be char array, not string literal)
    char sentence[] = "I,am,learning,C++";

    // Step 2: Define the delimiter
    const char* delimiter = ",";

    // Step 3: Call strtok for the first token
    char* token = strtok(sentence, delimiter);

    // Step 4: Loop to get all tokens
    while (token != nullptr) {
        std::cout << token << "\n";  // print each word
        token = strtok(nullptr, delimiter);  // get next word
    }

    return 0;
}

/*
🔹 Output:
I
am
learning
C++

🔸 What's Happening Behind the Scenes?
First call: strtok("I,am,learning,C++", ",") → returns "I" and remembers where it stopped.
Next calls: strtok(nullptr, ",") → continues from where it stopped and returns next words.

🔴 Important Rules
The input must be a char array, not a string literal.
❌ strtok("I,am,learning", ","); → error!
✅ char str[] = "I,am,learning";

It changes the original string by replacing commas with \0.
It is not thread-safe, but fine for simple programs.

🧠 Tip:
To split based on space, just change:
    char sentence[] = "This is simple";
    const char* delimiter = " ";

Then the output will be:
This
is
simple
*/
