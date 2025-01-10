#include <iostream>
#include <unordered_map>

using namespace std;

class MyHashMap {
public:
    unordered_map<int, int> m;
    MyHashMap() {
    }
    
    void put(int key, int value) {
        m[key] = value;
    }
    
    int get(int key) {
        return m.count(key) > 0 ? m[key] : -1;
    }
    
    void remove(int key) {
        m.erase(key);
    }
};