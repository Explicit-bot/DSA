/*
========================================
C++ CONTROL FLOW KEYWORDS
========================================
1. break
2. continue
3. return
4. exit()

----------------------------------------
1. break
----------------------------------------
Definition:
- break immediately exits the nearest loop or switch statement.

Works in:
- for loop
- while loop
- do-while loop
- switch

Does NOT work in:
- if
- else
- normal blocks {}

Syntax:

break;

----------------------------------------
Example 1: break in for loop
----------------------------------------

#include <iostream>
using namespace std;

int main() {

    for(int i=1; i<=5; i++) {

        if(i==3) {
            break;
        }

        cout << i << " ";
    }

    return 0;
}

Output:
1 2

Explanation:
- Loop starts from 1
- When i becomes 3
- break executes
- Entire loop stops immediately

----------------------------------------
Example 2: break in nested loops
----------------------------------------

#include <iostream>
using namespace std;

int main() {

    for(int i=1; i<=3; i++) {

        for(int j=1; j<=3; j++) {

            if(j==2) {
                break;
            }

            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}

Output:
1
1
1

Explanation:
- break only exits the NEAREST loop
- Here it exits inner loop only

----------------------------------------
Example 3: break in switch
----------------------------------------

#include <iostream>
using namespace std;

int main() {

    int day = 2;

    switch(day) {

        case 1:
            cout << "Monday";
            break;

        case 2:
            cout << "Tuesday";
            break;

        case 3:
            cout << "Wednesday";
            break;
    }

    return 0;
}

Output:
Tuesday

----------------------------------------
Important Notes about break
----------------------------------------

1. break exits loop completely
2. break affects nearest loop/switch only
3. break does NOT affect if statements
4. Program continues after loop ends

----------------------------------------
2. continue
----------------------------------------

Definition:
- continue skips the current iteration
- Loop itself does NOT stop

Works in:
- for loop
- while loop
- do-while loop

Syntax:

continue;

----------------------------------------
Example 1: continue in for loop
----------------------------------------

#include <iostream>
using namespace std;

int main() {

    for(int i=1; i<=5; i++) {

        if(i==3) {
            continue;
        }

        cout << i << " ";
    }

    return 0;
}

Output:
1 2 4 5

Explanation:
- When i becomes 3
- continue skips remaining code
- Loop moves to next iteration

----------------------------------------
Example 2: continue in while loop
----------------------------------------

#include <iostream>
using namespace std;

int main() {

    int i = 1;

    while(i <= 5) {

        if(i == 3) {
            i++;
            continue;
        }

        cout << i << " ";
        i++;
    }

    return 0;
}

Output:
1 2 4 5

----------------------------------------
Important continue mistake
----------------------------------------

WRONG CODE:

while(i <= 5) {

    if(i == 3) {
        continue;
    }

    i++;
}

Problem:
- Infinite loop
- i never changes after becoming 3

Reason:
- continue skips i++

========================================
continue INSIDE switch
========================================

IMPORTANT:
- continue does NOT work directly with switch
- continue only works with loops

------------------------------------------------
Case 1: continue inside standalone switch
------------------------------------------------

#include <iostream>
using namespace std;

int main() {

    int x = 1;

    switch(x) {

        case 1:
            continue;
    }

    return 0;
}

Result:
ERROR

Reason:
- switch is NOT a loop
- continue requires:
    1. for loop
    2. while loop
    3. do-while loop

Compiler Error:
"continue statement not within a loop"

------------------------------------------------
Case 2: switch inside loop
------------------------------------------------

#include <iostream>
using namespace std;

int main() {

    for(int i=1; i<=5; i++) {

        switch(i) {

            case 3:
                continue;
        }

        cout << i << " ";
    }

    return 0;
}

Output:
1 2 4 5

------------------------------------------------
Explanation
------------------------------------------------

When i == 3:

continue executes

C++ searches upward for nearest LOOP:
- for
- while
- do-while

It ignores switch completely.

So:
- current loop iteration is skipped
- next iteration begins

------------------------------------------------
IMPORTANT DIFFERENCE
------------------------------------------------
Inside switch-in-loop:

break
- exits switch only

continue
- skips current loop iteration

------------------------------------------------
Example: break inside switch
------------------------------------------------
#include <iostream>
using namespace std;

int main() {

    for(int i=1; i<=3; i++) {

        switch(i) {

            case 2:
                break;
        }

        cout << i << " ";
    }

    return 0;
}

Output:
1 2 3

Reason:
- break exits switch only
- loop continues normally

------------------------------------------------
Example: continue inside switch
------------------------------------------------
#include <iostream>
using namespace std;

int main() {

    for(int i=1; i<=3; i++) {

        switch(i) {

            case 2:
                continue;
        }

        cout << i << " ";
    }

    return 0;
}

Output:
1 3

Reason:
- continue skips entire loop iteration
- cout does not execute for i == 2

----------------------------------------
Important Notes about continue
----------------------------------------
1. continue skips CURRENT iteration only
2. Loop still continues
3. continue does NOT stop loop
4. Be careful in while loops
5. continue NEVER affects switch
6. continue ALWAYS affects nearest loop

----------------------------------------
3. return
----------------------------------------

Definition:
- return immediately exits the current function

Syntax:

return value;

OR

return;

----------------------------------------
Example 1: returning value
----------------------------------------

#include <iostream>
using namespace std;

int add(int a, int b) {

    return a + b;
}

int main() {

    cout << add(2,3);

    return 0;
}

Output:
5

----------------------------------------
Example 2: return inside loop
----------------------------------------

#include <iostream>
using namespace std;

void func() {

    for(int i=1; i<=5; i++) {

        if(i==3) {
            return;
        }

        cout << i << " ";
    }

    cout << "Hello";
}

int main() {

    func();

    return 0;
}

Output:
1 2

Explanation:
- return exits ENTIRE function
- Not just loop

----------------------------------------
return in main()
----------------------------------------

return 0;

Meaning:
- Program ended successfully

----------------------------------------
Important Notes about return
----------------------------------------

1. return exits function immediately
2. return can send value back
3. return stops all remaining function code
4. return inside loop exits function too

----------------------------------------
4. exit()
----------------------------------------

Definition:
- exit() immediately terminates ENTIRE program

Header File:

#include <cstdlib>

Syntax:

exit(0);

----------------------------------------
Example
----------------------------------------

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    cout << "Hello";

    exit(0);

    cout << "World";
}

Output:
Hello

Explanation:
- Program ends immediately after exit()

----------------------------------------
exit() Status Codes
----------------------------------------

exit(0)
- successful termination

exit(1)
- abnormal termination/error

----------------------------------------
Important Notes about exit()
----------------------------------------

1. exit() stops whole program
2. exit() can be used anywhere
3. No code executes after exit()

========================================
DIFFERENCE TABLE
========================================

---------------------------------------------------------
Keyword      Meaning              Scope
---------------------------------------------------------
break        exits loop           nearest loop/switch
continue     skips iteration      current iteration
return       exits function       current function
exit()       stops program        entire program
---------------------------------------------------------

========================================
MENTAL MODEL
========================================

continue
= skip this iteration

break
= stop this loop

return
= stop this function

exit()
= stop this program

========================================
FLOW HIERARCHY
========================================

Program
 └── Functions
      └── Loops
           └── Iterations

continue
- affects iteration

break
- affects loop

return
- affects function

exit()
- affects entire program

========================================
MOST COMMON BEGINNER MISTAKES
========================================

1. Using break outside loops
   -> compiler error

2. Forgetting break in switch
   -> fallthrough happens

3. Infinite loop with continue in while loop

4. Confusing break and return

5. Thinking break exits if statement
   -> WRONG

========================================
IMPORTANT FINAL RULE
========================================

if decides WHETHER break/continue/return executes

BUT:

break exits loop
continue skips iteration
return exits function
exit() terminates program

if itself is never exited by break
*/
