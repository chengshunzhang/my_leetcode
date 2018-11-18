#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

class LFUCache {
private:
    int maxSize, min;
    unordered_map<int, pair<int, int> > keyNodes; // key -> (value, freq)
    unordered_map<int, list<int> > freqNodes; // freq -> list of keys
    unordered_map<int, list<int>::iterator> keyInList; // key -> iterator
public:
    LFUCache(int capacity) {
        maxSize = capacity;
        min = ((uint)1 << 31) - 1;
    }
    
    int get(int key) {
        if(!keyNodes.count(key)) {
            return -1;
        }
        int freq = keyNodes[key].second;
        if(freqNodes[freq].size() == 1) {
            freqNodes.erase(freqNodes.find(freq));
            if(min == freq) {
                min++;
            }
        } else {
            freqNodes[freq].erase(keyInList[key]);
        }
        freq = ++keyNodes[key].second;
        freqNodes[freq].push_front(key);
        keyInList[key] = freqNodes[freq].begin();
        return keyNodes[key].first;
    }
    
    void put(int key, int value) {
        if(!maxSize) {
            return;
        }
        if(keyNodes.count(key)) {
            keyNodes[key].first = value;
            get(key);
            return;
        }
        if(keyNodes.size() < maxSize) {
            keyNodes[key] = make_pair(value, 1);
            freqNodes[1].push_front(key);
            keyInList[key] = freqNodes[1].begin();
            if(min > 1) {
                min = 1;
            }
        } else {
            int removedKey = freqNodes[min].back();
            keyNodes.erase(keyNodes.find(removedKey));
            if(freqNodes[min].size() == 1) {
                freqNodes.erase(freqNodes.find(min));
            } else {
                freqNodes[min].pop_back();
            }
            keyInList.erase(keyInList.find(removedKey));
            put(key, value);
        }
    }
};

int main() {
	LFUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;       // returns 1
	cache.put(3, 3);    // evicts key 2
	cout << cache.get(2) << endl;       // returns -1 (not found)
	cout << cache.get(3) << endl;       // returns 3.
	cache.put(4, 4);    // evicts key 1.
	cout << cache.get(1) << endl;       // returns -1 (not found)
	cout << cache.get(3) << endl;       // returns 3
	cout << cache.get(4) << endl;       // returns 4
	return 0;
}