#include <vector>
#include <iostream>
using namespace std;

bool myComp(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.second < p2.second;
}

class Solution {
public:
    int minTotalDistance(vector<vector<int> >& grid) {
        int m = grid.size(), n = grid[0].size(), result = 0;
        vector<pair<int, int> > houses;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    houses.push_back(make_pair(i, j));
                }
            }
        }
        sort(houses.begin(), houses.end());
        int left = 0, right = houses.size() - 1;
        while(left < right) {
            result += houses[right--].first - houses[left++].first;
        }
        sort(houses.begin(), houses.end(), myComp);
        left = 0, right = houses.size() - 1;
        while(left < right) {
            result += houses[right--].second - houses[left++].second;
        }
        return result;
    }
};

int main() {
	vector<vector<int> > grid(3, vector<int> (5, 0));
	grid[0][0] = grid[0][4] = grid[2][2] = 1;
	Solution s;
	cout << s.minTotalDistance(grid) << endl;
	return 0;
}