#include "Set.h"
#include <iostream>
#include <vector>
using namespace std;

Set::Set(int nums_size) {
    size = nums_size;
    nums.resize(size);
    cur_size = 0;
}
Set::Set(const Set& other) {
    size = other.size;
    cur_size = other.cur_size;
    nums = other.nums;
}

Hash Set::hash(int num) {
    Hash h;
    h.contains = false;
    int i = 0;
    vector<int> seen;
    do {
        h.index = (num + i) % size;
        for (int num: seen) if (num == h.index) return h;
        seen.push_back(h.index);
        if (nums.at(h.index).has_value() && nums.at(h.index).value() == num) {
            h.contains = true;
            return h;
        }    
        i++;
    } while (nums.at(h.index).has_value());
    return h;
}

bool Set::contains(int num) { 
    if (cur_size < 1) return false;
    return hash(num).contains;
 }

void Set::add(int num) {
    if (cur_size >= size) return;
    Hash h = hash(num);
    if (h.contains) return;
    cur_size++;
    nums[h.index] = num;
}

void Set::addAll(vector<int> values) {
    for (int num: values) add(num);
}

void Set::remove(int num) {
    Hash h = hash(num);
    if (!h.contains) return;
    nums[h.index].reset();
    cur_size--;
}

void Set::removeAll(vector<int> values) {
    for (int num: values) remove(num);
}

Set Set::operator&(Set other) {
    vector<int> res;
    Set min = cur_size < other.cur_size ? *this : other;
    Set max = cur_size < other.cur_size ? other : *this;
    int len = 0;
    for (optional<int> num: min.nums) {
        if (num.has_value() && max.contains(num.value())) {
            len++;
            res.push_back(num.value());
        }
    }        
    Set new_set(len);
    new_set.addAll(res);
    return new_set;
}

Set Set::operator+(Set other) {
    Set res(cur_size + other.cur_size - (*this & other).size);
    for (optional<int> num: nums) if (num.has_value()) res.add(num.value());
    for (optional<int> num: other.nums) if (num.has_value()) res.add(num.value());
    return res;
}

Set Set::operator-(Set other) {
    Set intersect = *this & other;
    Set res(cur_size - intersect.size);

    for (optional<int> num: nums) {
        if (num.has_value() && !intersect.contains(num.value())) {
            res.add(num.value());
        }
    }    
    return res;
}

bool Set::operator>(Set other) { 
    int intersection = (*this & other).cur_size;
    return cur_size >= intersection && other.cur_size == intersection;
}
bool Set::operator<(Set other) { return cur_size == (*this & other).cur_size; }

void Set::print() {
    cout << "{ ";
    for (optional<int> num: nums) 
        if(num.has_value()) cout << num.value() << " "; 
    cout << "}\n";
}

void Set::actual_print() {
    cout << "{ ";
    for (optional<int> num: nums) 
        if(num.has_value()) cout << num.value() << " "; 
        else cout << "null ";
    cout << "}\n";
}