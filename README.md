# C++ Set Data Structure

This is a **pet project** to learn C++.  
> [!NOTE]
> It may be unsafe, not follow best practices, and not be the fastest implementation.  

## Overview

This project implements a basic integer `Set` with operations like:
- Adding/removing elements
- Union, intersection, and difference
- Containment checks
- Printing

The set uses a simple hash table with linear probing. Test cases are available in test.cpp.

---

## Time Complexity of Functions

| Function                        | Complexity                         | Notes                                                                                             |
|---------------------------------|------------------------------------|---------------------------------------------------------------------------------------------------|
| `contains(int num)`             | O(1)                               | Fully dependent on `hash()` which is normally O(1). Can be made faster by skipping duplicate-check loop. |
| `add(int num)`                  | O(1)                               | Same note as `contains()`.                                                                        |
| `addAll(vector<int> values)`    | O(n)                               | Where *n* = size of input vector.                                                                 |
| `remove(int num)`               | O(1)                               | Same note as `contains()`.                                                                        |
| `removeAll(vector<int> values)` | O(n)                               | Same as `addAll()`.                                                                               |
| `operator&(Set other)`          | O(m)                               | Intersection where *m* = min(size of both sets).                                                  |
| `operator+(Set other)`          | O(m + n)                           | Union of two sets (*m* and *n* = sizes of sets).                                                 |
| `operator-(Set other)`          | O(m + a)                           | Difference, m = min(size of both sets), *a* = size of left set.                                                               |
| `operator>(Set other)`          | O(m)                               | Same as intersection.                                                                             |
| `operator<(Set other)`          | O(m)                               | Same as intersection.                                                                             |
| `print()`                       | O(n)                               | Iterates over all slots.                                                                          |
| `actual_print()`                | O(n)                               | Same as `print()`, but shows `null` for empty slots.                                             |

---

## Example Usage

```cpp
#include "Set.h"
#include <vector>
using namespace std;

int main() {
    Set s1(10);
    s1.add(1);
    s1.add(2);
    s1.add(3);
    //or s1.addAll({1,2,3});

    Set s2(10);
    s2.add(3);
    s2.add(4);
    //or s1.addAll({10,3,4});

    Set intersection = s1 & s2;
    Set unionSet = s1 + s2;
    Set difference = s1 - s2;

    intersection.print();  // { 3 }
    unionSet.print();      // { 1 2 3 4 }
    difference.print();    // { 1 2 }
}