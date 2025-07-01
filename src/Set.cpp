#include "Set.h"
#include <iostream>
using namespace std;

Set::Set(int size) {
    this->size = size;
    this->cur_size = 0;
    nums = new int[size];
}
Set::Set(const Set& other) {
    size = other.size;
    cur_size = other.cur_size;
    nums = new int[size];
    for (int i = 0; i < cur_size; i++) {
        nums[i] = other.nums[i];
    }
}
Set::~Set() { delete[] nums; }

bool Set::contains(int num) {
    for (int i=0; i<cur_size; i++) {
        if (nums[i] == num) return true;
    }
    return false;
}

int Set::intersect_len(Set other) {
    int len = 0;
    for (int i=0; i<cur_size; i++) len += other.contains(nums[i]) ? 1 : 0;
    return len;
}

void Set::add(int num) {
    if (cur_size < size && !contains(num)) {
        nums[cur_size] = num;
        cur_size++;
    }
}

void Set::addAll(int toadd[], int toadd_size) {
    for (int i=0; i<toadd_size; i++) add(toadd[i]);
}

void Set::remove(int num) {
    if (cur_size < 1) return;
    int match = -1;
    for (int i=0; i<cur_size; i++) {
        if (nums[i] == num) {
            match = i;
            break;
        }
    }
    if (match >= 0) {
        if (match < cur_size) {
            for (int i=match; i+1<cur_size; i++) {
                nums[i] = nums[i+1];
            }
        }
        cur_size--;
    }
}

void Set::removeAll(int toremove[], int toremove_size) {
    for (int i=0; i<toremove_size; i++) remove(toremove[i]);
}

Set Set::operator+(Set other) {
    Set res(cur_size + other.cur_size - intersect_len(other));
    res.addAll(nums, cur_size);
    res.addAll(other.nums, other.cur_size);
    return res;
}

Set Set::operator-(Set other) {
    Set res(cur_size - intersect_len(other));
    for (int i=0; i<cur_size; i++) {
        if (!other.contains(nums[i])) res.add(nums[i]);
    }
    return res;
}

void Set::print() {
    cout << "{ ";
    for (int i=0; i<size; i++) {
        if (i < cur_size) cout << nums[i] << " ";
        else cout << "null ";
    }
    cout << "}\n";
}