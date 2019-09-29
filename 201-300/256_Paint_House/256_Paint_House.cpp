#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) {
            return 0;
        }
        int min1 = costs[0][0], min2 = costs[0][1], min3 = costs[0][2];
        int preMin1, preMin2, preMin3;
        for(int i = 1; i < n; i++) {
            preMin1 = min1;
            preMin2 = min2;
            preMin3 = min3;
            min1 = costs[i][0] + min(preMin2, preMin3);
            min2 = costs[i][1] + min(preMin3, preMin1);
            min3 = costs[i][2] + min(preMin1, preMin2);
        }
        return min(min1, min(min2, min3));
    }
};

int main() {
    vector<vector<int>> costs = {{17, 2, 17}, {16, 16, 5}, {14, 3, 19}};
    Solution sol;
    cout << sol.minCost(costs) << endl;
    return 0;
}