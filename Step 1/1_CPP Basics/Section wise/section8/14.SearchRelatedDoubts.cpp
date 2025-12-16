/*
Duplicates in Search
searching is done in unique list of elements.
If there are duplicates we can’t perform search.
If they are duplicates then you should look for all occurrences of a
element.
Example:
List : 8,5,7,8,10,8,2,7,8
Here 8 is appearing 4 time. If you search for 8, then which 8 you
want?

🧠 Problem Recap:
You're given a list (possibly unsorted) with duplicates, like:

    List: 8, 5, 7, 8, 10, 8, 2, 7, 8
If someone says:
"Search for 8"
We face the question:

"Which one?"
First occurrence?
All occurrences?
Last occurrence?

So in duplicate-friendly lists, a single “search” isn’t enough unless you know what you want.

✅ 1. First Occurrence

    int index = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            index = i;
            break; // exit loop after first match
        }
    }
Use this when you only care where the key starts.

✅ 2. All Occurrences

    vector<int> indices;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }

This is useful when you want to find all positions of a value.

In CP, it helps when you’re solving frequency or matching problems.

✅ 3. Count Occurrences

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key)
            ++count;
    }

Useful when solving problems like:

"Check if a number appears more than k times"

✅ 4. Last Occurrence
Just continue scanning, and overwrite index on each match:

    int index = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key)
            index = i;
    }
🔥 For Sorted Arrays (Duplicates + Binary Search)
Use std::lower_bound and std::upper_bound:

    #include <algorithm>  // Required for lower_bound, upper_bound

    int* first = std::lower_bound(arr, arr+n, key);  // first occurrence
    int* last = std::upper_bound(arr, arr+n, key);   // just after last

    int count = last - first;  // number of occurrences

✅ Works in O(log n) for sorted arrays

🧠 Summary
Task	                Method	                        Works On
First occurrence	    Break on first match	        Any list
All occurrences	        Store indices	                Any list
Count occurrences	    Count matches	                Any list
Last occurrence	        Overwrite index on match	    Any list
Fast (sorted only)	    lower_bound, upper_bound	    Sorted arrays
*/
