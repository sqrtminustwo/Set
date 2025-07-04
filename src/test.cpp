#include "Set.h"
#include <iostream>
#include <cassert>
using namespace std;

void testContains() {
    Set s1(5);
    s1.addAll({1,2,3,4,5});
    assert(s1.contains(1));
    assert(s1.contains(5));
    assert(!s1.contains(10));
    assert(!s1.contains(0));

    Set s2(5);
    assert(!s2.contains(1));
    assert(!s2.contains(0));
    cout << "Passed contains tests." << "\n";
}

void testIntersection() {
    Set a1(5);
    Set a2(10);
    a1.addAll({1, 2, 3, 4, 5});
    a2.addAll({2, 3, 5, 7, 8, 9, 10});
    Set inter1 = a1 & a2;

    vector<int> expected1 = {2, 3, 5};
    for (int num: expected1) {
        assert(inter1.contains(num));
    }

    vector<int> unexpected1 = {1, 4, 7, 8, 9, 10};
    for (int num: unexpected1) {
        assert(!inter1.contains(num));
    }

    Set b1(5);
    Set b2(10);
    Set inter2 = b1 & b2;
    vector<int> unexpected2 = {-1, 0, 1};
    for (int num: unexpected2) {
        assert(!inter2.contains(num));
    }

    Set c1(5);
    Set c2(4);
    c1.addAll({1,2,3});
    Set inter3= c1 & c2;
    vector<int> unexpected3 = {1, 2, 3};
    for (int num: unexpected3) {
        assert(!inter3.contains(num));
    }

    Set d1(10);
    Set d2(10);
    d1.addAll({1,2,3,4,5,6,7,8,9,10});
    d2.addAll({1,2,3,4,5,6,7,8,9,10});
    Set inter4= d1 & d2;
    vector<int> expected4 = {1,2,3,4,5,6,7,8,9,10};
    for (int num: expected4) {
        assert(inter4.contains(num));
    }

    cout << "Passed intersection tests." << "\n";
}

void testUnion() {
    Set s1(5);
    Set s2(10);
    s1.addAll({1, 2, 3, 4, 5});
    s2.addAll({2, 3, 5, 7, 8, 9, 10});
    Set u = s1 + s2;
    vector<int> expected = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    for (int x : expected) {
        assert(u.contains(x));
    }

    cout << "Passed non empty union test." << "\n";
}

void testDifference() {
    Set s1(10);
    Set s2(10);
    s1.addAll({1, 2, 3, 4, 5, 6});
    s2.addAll({3, 4, 5});
    Set diff = s1 - s2;
    vector<int> expected = {1, 2, 6};
    for (int x : expected) {
        assert(diff.contains(x));
    }
    vector<int> notExpected = {3, 4, 5};
    for (int x : notExpected) {
        assert(!diff.contains(x));
    }

    cout << "Passed non empty difference test." << "\n";
}

void testEmptyUnionDifference() {
    Set a(5);
    Set b(5);
    a.addAll({});
    b.addAll({1, 2, 3});

    Set u = a + b;
    vector<int> expected = {1, 2, 3};
    for (int x : expected) {
        assert(u.contains(x));
    }

    Set d = b - a;
    for (int x : expected) {
        assert(d.contains(x));
    }

    Set emptyInter = a & b;
    for (int x : expected) {
        assert(!emptyInter.contains(x));
    }

    cout << "Passed empty union test." << "\n";
}

void testLessGreater() {
    Set a(7);
    Set b(7);
    a.addAll({1, 2, 3});
    b.addAll({1, 2, 3, 4});
    assert(a < b);
    assert(!(b < a));
    assert(b > a);
    assert(!(a > b));

    Set c(7);
    Set d(7);
    c.addAll({2, 4, 6});
    d.addAll({1, 3, 5, 7});
    assert(!(c < d));
    assert(!(d < c));
    assert(!(c > d));
    assert(!(d > c));

    cout << "Passed subset/superset tests." << "\n";
}

int main() {
    testContains();
    testIntersection();
    testUnion();
    testDifference();
    testLessGreater();
    testEmptyUnionDifference();
    cout << "All tests passed.\n";
    return 0;
}