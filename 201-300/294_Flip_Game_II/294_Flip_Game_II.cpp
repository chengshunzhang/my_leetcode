#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
private:
    bool helper(string& s, unordered_map<string, bool>& myMap) {
        if(myMap.find(s) == myMap.end()) {
            myMap[s] = false;
            int first = 0, second = 1, n = s.size();
            while(second < n) {
                if(s[first] == '+' && s[second] == '+') {
                    s[first] = s[second] = '-';
                    bool win = helper(s, myMap);
                    s[first] = s[second] = '+';
                    if(!win) {
                        myMap[s] = true;
                        break;
                    }
                }
                first++;
                second++;
            }
        }
        return myMap[s];
    }
public:
    bool canWin(string s) {
        unordered_map<string, bool> myMap;
        return helper(s, myMap);
    }
};

int main() {
    string s = "++++";
    Solution sol;
    cout << sol.canWin(s) << endl;
    return 0;
}