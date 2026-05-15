/* 
CONDITIONAL STATEMENTS 
1️⃣ IF STATEMENT (Single Condition)
• Used when code should execute ONLY if condition is true.
• If condition is false → nothing happens.
• Time Complexity: O(1)
• Condition must be boolean (true/false)

Syntax:
if (condition) {
    statement(s);
}

e.g.
    if (age >= 18) {
        cout << "You can vote\n";
    }

2️⃣ IF - ELSE STATEMENT (Two Paths)
👉 Used when exactly ONE of two blocks must execute.
👉 Either if OR else runs, never both.

Syntax:
if (condition) {
    // true block
} else {
    // false block
}

e.g.
    if (marks >= 40) {
        cout << "Pass\n";
    } else {
        cout << "Fail\n";
    }

3️⃣ ELSE IF LADDER (Multiple Conditions)
• Used when multiple MUTUALLY EXCLUSIVE conditions exist.
• Conditions are checked from TOP to BOTTOM.  
• Order matters (highest → lowest)
• First true condition executes.
• Remaining conditions are skipped.     
• Only ONE block executes
• else is optional but recommended

Syntax:
if (condition1) {
}
else if (condition2) {
}
else if (condition3) {
}
else {
}

e.g.
    if (marks >= 90) {
        cout << "Grade A\n";
    }
    else if (marks >= 75) {
        cout << "Grade B\n";
    }
    else if (marks >= 60) {
        cout << "Grade C\n";
    }
    else {
        cout << "Fail\n";
    }

4️⃣ NESTED IF - ELSE (If inside If)
• Used when one decision DEPENDS on another decision.
• Hierarchical logic (parent → child condition)

Syntax:
if (condition1) {
    if (condition2) {
    } 
    else {
    }
} 
else {
}

e.g.
    if (age >= 18) {
        if (hasID) {
            cout << "Allowed entry\n";
        } 
        else {
            cout << "Bring ID\n";
        }
    } 
    else {
        cout << "Underage\n";
    }

5️⃣ ELSE IF LADDER vs NESTED IF
    // else-if ladder
        if (x > 0) {
            cout << "Positive\n";
        }
        else if (x < 0) {
            cout << "Negative\n";
        }
        else {
            cout << "Zero\n";
        }

    // nested if
        if (x >= 0) {
            if (x == 0) {
                cout << "Zero\n";
            } 
            else {
                cout << "Positive\n";
            }
        } 
        else {
            cout << "Negative\n";
        }

6️⃣ MULTIPLE IF vs ELSE IF (VERY IMPORTANT ⚠️)
MULTIPLE IF:
👉 ALL true conditions execute

ELSE IF:
👉 ONLY FIRST true condition executes

    // Multiple if
        if (x > 0) cout << "Positive ";
        if (x % 2 == 0) cout << "Even\n";

    // else-if
        if (x > 0) cout << "Positive ";
        else if (x % 2 == 0) cout << "Even\n";

IMPORTANT POINTS:
✔ Use multiple if when checks are independent
✔ Use else-if when only one case should run

7️⃣ Logical Operators
• If you are having more than one conditional statements and
wants to join them, then this concept is called compound
conditional statement and the operations using which this can be
done is called Logical Operator

Logical Operators are :
&&	 	 	 AND
||	 	 	 OR
!	 	 	 NOT

• && , || is used to make compound conditional statements
• while ! Is used for negations that is make a true statement false
and vice versa
• The values of AND , OR depends on their truth values because
they are logical

&& - AND 
• In AND if one is FALSE everything is FALSE
|| - OR
• In OR if one is TRUE everything is TRUE

e.g.
    if (age >= 18 && age <= 25) {
        cout << "Youth category\n";
    }

    if (!(age < 18)) {
        cout << "Adult\n";
    }

*/
