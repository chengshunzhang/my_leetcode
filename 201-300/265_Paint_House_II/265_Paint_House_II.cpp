#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) {
            return 0;
        }
        int k = costs[0].size();
        vector<int> mins(k);
        vector<int> preMins(k);
        for(int i = 0; i < k; i++) {
            mins[i] = costs[0][i];
        }
        for(int i = 1; i < n; i++) {
            int minimum = INT_MAX, secondMin;
            int id;
            for(int j = 0; j < k; j++) {
                preMins[j] = mins[j];
                if(preMins[j] < minimum) {
                    secondMin = minimum;
                    minimum = preMins[j];
                    id = j;
                } else if(preMins[j] < secondMin) {
                    secondMin = preMins[j];
                }
            }
            for(int j = 0; j < k; j++) {
                if(j != id) {
                    mins[j] = costs[i][j] + minimum;
                } else {
                    mins[j] = costs[i][j] + secondMin;
                }
            }
        }
        int result = INT_MAX;
        for(int j = 0; j < k; j++) {
            if(mins[j] < result) {
                result = mins[j];
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> costs = {{1, 5, 3}, {2, 9, 4}};
    Solution sol;
    cout << sol.minCostII(costs) << endl;
    return 0;
}