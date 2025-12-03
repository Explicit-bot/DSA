/*
Enumerated
• They method of defining enum is
Ex :
enum days { mon , tue , wed , thurs , fri , sat , sun };
            
            0     1     2      3      4     5     6

• Here you can access the values that are assigned to it already
you cannot define your own values here
Ex:
•   By default the index value assigned is 0 but you can change it if you
    want
    enum dept { CS=2, IT , EEE=9, CIVIL };
                 2    3     9       10
•   This feature and its usage is completely upto the programmer
•	Improves readability by replacing magic numbers with meaningful names.
•	Enforced by compiler — catches typos and invalid assignments.
•	Uses less memory and is faster than using strings.
•	Works with switch-case statements.
•	Can restrict variables to only valid enum values.
*/
#include <iostream>
using namespace std;

// Enum for traffic light colors
enum TrafficLight { RED = 1, YELLOW, GREEN };

void actionForLight(TrafficLight light) {
    switch (light) {
        case RED:
            cout << "STOP! 🚫" << endl;
            break;
        case YELLOW:
            cout << "Slow down! ⚠️" << endl;
            break;
        case GREEN:
            cout << "Go! ✅" << endl;
            break;
        default:
            cout << "Invalid traffic light!" << endl;
    }
}

int main() {
    TrafficLight currentLight = YELLOW;

    cout << "Traffic light code: " << currentLight << endl;
    actionForLight(currentLight);

    return 0;
}

/*
Traffic light code: 2
Slow down! ⚠️
*/
