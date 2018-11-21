#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class RandomizedCollection {
private:
    int size;
    vector<int> storage;
    unordered_map<int, unordered_set<int> > hash;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        size = 0;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        storage.push_back(val);
        hash[val].insert(size);
        bool result = hash[val].size() == 1 ? true : false;
        size++;
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(!hash.count(val) || hash[val].empty()) {
            return false;
        }
        size--;
        if(storage.back() == val) {
            storage.pop_back();
            hash[val].erase(hash[val].find(size));
        } else {
            int removePos = *hash[val].begin(), back = storage[size];
            storage[removePos] = back;
            hash[val].erase(hash[val].begin());
            hash[back].erase(hash[back].find(size));
            hash[back].insert(removePos);
            storage.pop_back();
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if(!size) {
            return 0;
        }
        return storage[rand() % size];
    }
};

int main() {
	RandomizedCollection obj;
	cout << obj.insert(0) << endl;
	cout << obj.insert(1) << endl;
	cout << obj.remove(0) << endl;
	cout << obj.insert(2) << endl;
	cout << obj.remove(1) << endl;
	cout << obj.getRandom() << endl;
	return 0;
}