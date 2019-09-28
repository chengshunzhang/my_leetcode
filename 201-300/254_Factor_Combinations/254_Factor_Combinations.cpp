#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<vector<int>> helper(int n, int start) {
        vector<vector<int>> result;
        for(int i = start; i * i <= n; i++) {
            if(n % i == 0) {
                vector<int> temp(1, i);
                temp.push_back(n / i);
                result.push_back(temp);
                vector<vector<int>> res = helper(n / i, i);
                for(vector<int> r : res) {
                    temp = {i};
                    temp.insert(temp.end(), r.begin(), r.end());
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
public:
    vector<vector<int>> getFactors(int n) {
        unordered_set<int> factored;
        return helper(n, 2);
    }
};

int main() {
    int n = 12;
    Solution sol;
    vector<vector<int>> result = sol.getFactors(n);
    for(vector<int> res : result) {
        for(int factor : res) {
            cout << factor << ' ';
        }
        cout << endl;
    }
    return 0;
}