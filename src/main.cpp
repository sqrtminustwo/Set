#include "Set.h"
#include <iostream>
using namespace std;

int main() {
    Set s1(5);
    s1.addAll({1,2,3,4,5});
    s1.print();
    s1.remove(5);
    s1.print();
    s1.add(5);
    s1.print();
    cout << s1.contains(6) << " " << s1.contains(5);
    // s2.addAll(nums2, 5);

    // s1.print();
    // s2.print();

    // Set added = s1 + s2;
    // Set removed = s1 - s2;
    // Set intersection = s1 & s2;

    // added.print();
    // removed.print();
    // intersection.print();
    // cout << (s1 > s2) << "\n";
    // cout << (s1 < s2) << "\n";
    // int nums3[] = {1,2,3};
    // int nums4[] = {1,2,3,4,5};
    // Set s3(3);
    // Set s4(5);
    // s3.addAll(nums3, 3);
    // s4.addAll(nums4, 5);
    // cout << (s3 > s4) << "\n";
    // cout << (s3 < s4) << "\n";

    // int test[10];
    // for (int i=0; i<10; i++) cout << test[i] << "\n";

    return 0;
}