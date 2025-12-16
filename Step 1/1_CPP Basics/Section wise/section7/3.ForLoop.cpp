#include <iostream>

int main(){
    int n{};
    std::cout<<"Enter n:";
    std::cin>>n;

    for(int i{0};i<=n;++i) 
    //inside initialization is optional meanining u can initialize at the start of the program to
    {
        std::cout<<"i "<<i<<std::endl;  
        //can write ++i here too
        //it means if u initialize the variable at start of main and u write ++i here your for loop may look like    for( ;i<=n; ){ }
    }
   
    return 0;
}
/*
===============================
        📘 For Loop Syntax
===============================
🔧 General format:
    for(initialization; condition; update) {
        // body
    }

Parts of a for loop:
1. initialization → executed once at the beginning.
2. condition      → evaluated before every iteration (must be a boolean).
3. update         → executed after each iteration of the body.

--------------------------------
✅ Multiple Initializations / Updates
--------------------------------
- You can combine multiple initializations or multiple updates using commas (,).
- Example:
    for(int i = 0, j = len - 1; i < len; i++, j--) {
        rev[i] = str[j];
    }

Explanation:
- int i = 0, j = len - 1 → multiple initializations (allowed ✅).
- i < len                → a single condition.
- i++, j--               → multiple updates (allowed ✅).

--------------------------------
❌ Condition with Comma (Invalid)
--------------------------------
- You cannot put multiple conditions separated by commas.
- Why? Because the comma operator evaluates left-to-right,
  but only the last expression is returned as the result.

⚠️ Example (wrong behavior):
    for(int i = 0, j = 10; i < 5, j > 0; i++, j--) {
        cout << i << " " << j << endl;
    }

👉 Here, only "j > 0" is considered as the condition.
   "i < 5" is ignored completely!

--------------------------------
✅ Correct Way → Use Logical Operators
--------------------------------
- If you want multiple conditions, combine them with && (AND) or || (OR).

✔ Example (correct):
    for(int i = 0, j = 10; i < 5 && j > 0; i++, j--) {
        cout << i << " " << j << endl;
    }

Now the loop runs as long as BOTH conditions are true.

--------------------------------
⚖️ Summary
--------------------------------
- Initialization → multiple allowed using commas ✅
- Update        → multiple allowed using commas ✅
- Condition     → must be a single boolean expression ❌
                (use && or || if you need multiple checks)
- Using comma in condition → only last expression counts ⚠️
*/




