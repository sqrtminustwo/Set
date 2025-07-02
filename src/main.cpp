#include "Set.h"
#include <iostream>
using namespace std;

int main() {
    Set s1(5);
    Set s2(10);
    int nums1[] = {1,2,3,4,5};
    int nums2[] = {2,3,4,-2,6};
    s1.addAll(nums1, 5);
    s2.addAll(nums2, 5);

    s1.print();
    s2.print();

    Set added = s1 + s2;
    Set removed = s1 - s2;
    Set intersection = s1 & s2;

    added.print();
    removed.print();
    intersection.print();
    cout << (s1 > s2) << "\n";
    cout << (s1 < s2) << "\n";
    int nums3[] = {1,2,3};
    int nums4[] = {1,2,3,4,5};
    Set s3(3);
    Set s4(5);
    s3.addAll(nums3, 3);
    s4.addAll(nums4, 5);
    cout << (s3 > s4) << "\n";
    cout << (s3 < s4) << "\n";
    return 0;
}