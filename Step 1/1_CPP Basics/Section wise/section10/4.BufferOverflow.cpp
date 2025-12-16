/*
What Is a Buffer Overflow?
A buffer overflow occurs when more data is written into a memory location than it can hold, corrupting adjacent memory.

In C++, this happens when:
 You have a fixed-size array (like char name[10])
 And try to store more than 9 characters (1 is reserved for '\0')
 Using an input method that doesn’t enforce the size limit properly

🔍 cin (>>) vs cin.getline()
Let’s compare them side-by-side using this code:
    char name[10];
    cin >> name;            // Method 1: cin >>
    cin.getline(name, 10); // Method 2: cin.getline
💥 1. cin >> name; — The Unsafe One
User input:
Supercalifragilistic\n

What Happens:
cin >> reads until it finds whitespace → Supercalifragilistic
It doesn't check the buffer size!
It tries to write entire string into name[10]

BOOM! 💣 Buffer overflow occurs — you only allocated space for 10 chars, it tries to write 21+ chars.

Input buffer:
Whitespace (\n) is left behind
Memory after name is corrupted → Undefined behavior

✅ 2. cin.getline(name, 10); — The Safe One
User input:
    Supercalifragilistic\n

What Happens:
 - cin.getline reads at most 10 - 1 = 9 characters
 - Stores "Supercali" into name
 - Adds '\0' safely
 - Leaves "fragilistic\n" in the input buffer
 - No overflow. ✅

🔍 Internals – Why cin >> Can Overflow
    char name[10];
    cin >> name;

Internally:
 - Reads characters one-by-one from stdin
 - Keeps writing to name[i++] until:
 - Whitespace (' ', \n) OR EOF
 - But it has no knowledge of how big name actually is!

→ It writes blindly until something tells it to stop — which is dangerous.

🧪 Visual Memory Illustration
Input: "Supercalifragilistic\n"
With char name[10];

❌ cin >> name;
    name:      [S][u][p][e][r][c][a][l][i][f] ← OVERFLOW!
    corruption: [r][a][g][i][l]... ← overwriting other memory

✅ cin.getline(name, 10);
    name:      [S][u][p][e][r][c][a][l][i]['\0']
    input buffer: "fragilistic\n"

🧠 If You Use cin with char Arrays, Always Be Careful!
If you're doing this:
    char input[10];
    cin >> input;

You must manually limit the input or switch to cin.getline().
*/
