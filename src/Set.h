#ifndef SET_H
#define SET_H
#include <vector>
#include <optional>
using namespace std;

struct Hash {
    int index;
    bool contains;
};

class Set {
private:
    int size;
    int cur_size;
    vector<optional<int>> nums;
    Hash hash(int num);
public:
    Set(int nums_size);
    Set(const Set &other);
    bool contains(int num);
    void add(int num);
    void addAll(vector<int> values);
    void remove(int num);
    void removeAll(vector<int> values);
    Set operator+(Set other);
    Set operator-(Set other);
    Set operator&(Set other);
    bool operator>(Set other);
    bool operator<(Set other);
    void print();
    void actual_print();
};


#endif