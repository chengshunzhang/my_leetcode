#include <vector>
#include <list>
#include <iostream>
using namespace std;

class MyHashMap {
private:
    vector<list<pair<int, int> > > hash;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        hash.resize(10000);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = key % 10000;
        if(!hash[idx].empty()) {
            for(list<pair<int, int> >::iterator it = hash[idx].begin(); it != hash[idx].end(); it++) {
                if((*it).first == key) {
                    (*it).second = value;
                    return;
                }
            }
            
        }
        hash[idx].push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = key % 10000;
        if(hash[idx].empty()) {
            return -1;
        }
        for(list<pair<int, int> >::iterator it = hash[idx].begin(); it != hash[idx].end(); it++) {
            if((*it).first == key) {
                return (*it).second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = key % 10000;
        if(!hash[idx].empty()) {
            for(list<pair<int, int> >::iterator it = hash[idx].begin(); it != hash[idx].end(); it++) {
                if((*it).first == key) {
                    hash[idx].erase(it);
                    return;
                }
            }
        }
    }
};

int main() {
	MyHashMap myHash;
	myHash.put(1, 1);
	myHash.put(2, 2);
	cout << myHash.get(1) << endl;
	cout << myHash.get(3) << endl;
	myHash.put(2, 1);
	cout << myHash.get(2) << endl;
	myHash.remove(2);
	cout << myHash.get(2) << endl;
	return 0;
}