#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class RandomizedSet {
private:
    int size;
    unordered_map<int, int> hash;
    vector<int> storage;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        size = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash.count(val)) {
            return false;
        }
        storage.push_back(val);
        hash[val] = size;
        size++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!hash.count(val)) {
            return false;
        }
        storage[hash[val]] = storage.back();
        hash[storage.back()] = hash[val];
        hash.erase(hash.find(val));
        storage.pop_back();
        size--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(!size) {
            return 0;
        }
        return storage[rand() % size];
    }
};

int main() {
	RandomizedSet obj;
	cout << obj.insert(1) << endl;
	cout << obj.remove(2) << endl;
	cout << obj.insert(2) << endl;
	cout << obj.getRandom() << endl;
	cout << obj.remove(1) << endl;
	cout << obj.insert(2) << endl;
	cout << obj.getRandom() << endl;
	return 0;
}