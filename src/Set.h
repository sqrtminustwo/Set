#ifndef SET_H
#define SET_H
#include <vector>

class Set {
private:
    int size;
    int cur_size;
    int *nums;
    bool contains(int num);
public:
    Set(int size);
    Set::Set(const Set &other);
    ~Set();
    void add(int num);
    void addAll(int toadd[], int toadd_size);
    void addAll(std::vector<int> values);
    void remove(int num);
    void removeAll(int toremove[], int toremove_size);
    Set operator+(Set other);
    Set operator-(Set other);
    Set operator&(Set other);
    bool operator>(Set other);
    bool operator<(Set other);
    void print();
};

#endif