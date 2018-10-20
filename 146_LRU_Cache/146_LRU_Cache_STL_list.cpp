#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;

class LRUCache {
private:
    unordered_map<int, list<pair<int, int> >::iterator> m;
    list<pair<int, int> > ls;
    int size, max_size;
public:
    LRUCache(int capacity) {
        max_size = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(m.count(key)) {
            int k = m[key] -> first, v = m[key] -> second;
            ls.erase(m[key]);
            ls.push_front(pair<int, int> (k, v));
            m[key] = ls.begin();
            return m[key] -> second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(m.count(key)) {
            ls.erase(m[key]);
            ls.push_front(pair<int, int> (key, value));
            m[key] = ls.begin();
        } else {
            if(size < max_size) {
                size++;
            } else {
                m.erase(m.find(ls.back().first));
                ls.pop_back();
            }
            ls.push_front(pair<int, int> (key, value));
            m[key] = ls.begin();
        }
    }
    
};

int main() {
    LRUCache obj(2);
    obj.put(1, 1);
    obj.put(2, 2);
    cout << obj.get(1) << endl;
    obj.put(3, 3);
    cout << obj.get(2) << endl;
    obj.put(4, 4);
    cout << obj.get(1) << endl;
    cout << obj.get(3) << endl;
    cout << obj.get(4) << endl;
    return 0;
}