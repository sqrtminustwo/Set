#include "Set.h"
#include <iostream>
using namespace std;

int main() {
    Set s1(5);
    Set s2(10);
    s1.addAll({1,2,3,4,5});
    s2.addAll({2,3,5,7,8,9,10});
    (s1 & s2).print();
    (s2+s1).print();
    (s2-s1).print();

    cout << "\n";

    Set a1(5);
    Set a2(5);
    a1.addAll({1, 2, 3});
    a2.addAll({4, 5});
    (a1 & a2).print();
    (a1+a2).print();
    (a1-a2).print();

    cout << "\n";

    Set b1(10);
    Set b2(10);
    b1.addAll({1, 2, 3, 4, 5});
    b2.addAll({3, 4, 5, 6, 7});
    (b1 & b2).print();
    (b1+b2).print();
    (b1-b2).print();

    cout << "\n";

    Set c1(5);
    Set c2(5);
    c1.addAll({1, 2, 3, 4, 5});
    c2.addAll({1, 2, 3, 4, 5});
    (c1 & c2).print();
    (c1+c2).print();
    (c1-c2).print();

    cout << "\n";

    Set d1(8);
    Set d2(8);
    d1.addAll({});
    d2.addAll({1, 2, 3});
    (d1 & d2).print();
    (d1+d2).print();
    (d2-d1).print();

    cout << "\n";

    Set e1(7);
    Set e2(7);
    e1.addAll({2, 4, 6});
    e2.addAll({1, 3, 5, 7});
    (e1 & e2).print();
    (e1+e2).print();
    (e1-e2).print();
    cout << (e1 < e2) << "\n";
    cout << (e2 < e1) << "\n";
    cout << (e2 > e1) << "\n";
    cout << (e1 > e2) << "\n";
    
    cout << "\n";

    Set f1(7);
    Set f2(7);
    f1.addAll({1, 2, 3});
    f2.addAll({1, 2, 3, 4});
    cout << (f1 < f2) << "\n";
    cout << (f2 < f1) << "\n";
    cout << (f2 > f1) << "\n";
    cout << (f1 > f2) << "\n";

    return 0;
}