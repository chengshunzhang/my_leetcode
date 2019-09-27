#include <unordered_map>
#include <iostream>
using namespace std;

class TwoSum {
private:
    unordered_map<int, int> myMap;
    int maxV = 0, minV = 0;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        myMap[number]++;
        maxV = max(maxV, number);
        minV = min(minV, number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if(value > 2 * maxV || value < 2 * minV) {
            return false;
        }
        for(auto it = myMap.begin(); it != myMap.end(); it++) {
            int theOther = value - it -> first;
            if(myMap.find(theOther) != myMap.end()) {
                if(theOther == it -> first && myMap[theOther] == 1) {
                    continue;
                }
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */

int main() {
    TwoSum twoSum;
    twoSum.add(1);
    twoSum.add(3);
    twoSum.add(5);
    cout << twoSum.find(4) << endl;
    cout << twoSum.find(7) << endl;
    return 0;
}