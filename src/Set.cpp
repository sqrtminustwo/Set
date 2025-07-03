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
    nums.assign(other.nums.begin(), other.nums.end());
}

Hash Set::hash(int num) {
    Hash h;
    h.contains = false;
    int i = 0;
    do {
        h.index = (num + i*i) % size;
        if (nums.at(h.index).has_value() && nums.at(h.index).value() == num) {
            h.contains = true;
            return h;
        }    
        i++;
    } while (nums.at(h.index).has_value());
    return h;
}

bool Set::contains(int num) { return hash(num).contains; }

void Set::add(int num) {
    //cout << "cur_size: " << cur_size << " size: " << size << "\n";
    if (cur_size >= size) return;
    //cout << "before hash\n";
    Hash h = hash(num);
    //cout << "trying adding " << num << " index = " << h.index << " contains = " << h.contains << "\n";
    if (h.contains) return;
    cur_size++;
    //cout << "added" << "\n\n";
    nums.insert(nums.begin() + h.index, optional<int>(num));
}

void Set::addAll(vector<int> values) {
    for (int num: values) add(num);
}


void Set::remove(int num) {
    Hash h = hash(num);
    if (!h.contains) return;
    nums.erase(nums.begin() + h.index);
    cur_size--;
}

void Set::removeAll(vector<int> values) {
    for (int num: values) remove(num);
}

Set Set::operator&(Set other) {
    vector<int> res;
    int len = 0;
    for (int i=0; i<size; i++) {
        optional<int> num = nums[i];
        if (num.has_value() && contains(num.value())) {
            len++;
            res.push_back(num.value());
        }
    }        
    Set new_set(len);
    new_set.addAll(res);
    return new_set;
}

// Set Set::operator+(Set other) {
//     Set res(cur_size + other.cur_size - (*this & other).size);
//     res.addAll(nums, cur_size);
//     res.addAll(other.nums, other.cur_size);
//     return res;
// }

// Set Set::operator-(Set other) {
//     Set intersect = *this & other;
//     Set res(cur_size - intersect.size);
//     for (int i=0; i<cur_size; i++) {
//         if (!intersect.contains(nums[i])) res.add(nums[i]);
//     }
//     return res;
// }

// bool Set::operator>(Set other) { 
//     int intersection = (*this & other).size;
//     return size >= intersection && other.size == intersection;
// }
// bool Set::operator<(Set other) { return size == (*this & other).size; }

void Set::print() {
    cout << "{ ";
    for (int i=0; i<nums.size(); i++) 
        if(nums.at(i).has_value()) cout << nums.at(i).value() << " "; 
    cout << "}\n";
}