#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
private:
    int getAncestor(vector<int>& unionFind, int ele) {
        while(unionFind[ele] >= 0) {
            ele = unionFind[ele];
        }
        return ele;
    }
    int weightedUnion(vector<int>& unionFind, int group1, int group2) {
        if(unionFind[group1] < unionFind[group2]) {
            unionFind[group1] -= unionFind[group2];
            unionFind[group2] = group1;
            return group1;
        } else {
            unionFind[group2] -= unionFind[group1];
            unionFind[group1] = group2;
            return group2;
        }
    }
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int> >& positions) {
        vector<int> unionFind(m * n, INT_MAX);
        vector<int> result;
        int num = 0, drow[] = {-1, 0, 1, 0}, dcol[] = {0, -1, 0, 1};
        for(int i = 0; i < positions.size(); i++) {
            int row = positions[i].first, col = positions[i].second, idx = row * n + col;
            set<int> islands;
            for(int j = 0; j < 4; j++) {
                int newRow = row + drow[j], newCol = col + dcol[j], newId = newRow * n + newCol;
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && unionFind[newId] != INT_MAX) {
                    islands.insert(getAncestor(unionFind, newId));
                }
            }
            if(islands.empty()) {
                unionFind[idx] = -1;
                num++;
            } else if(islands.size() == 1) {
                unionFind[idx] = *islands.begin();
                unionFind[*islands.begin()]--;
            } else {
                int group1 = *islands.begin();
                islands.erase(islands.begin());
                do {
                    int group2 = *islands.begin();
                    islands.erase(islands.begin());
                    group1 = weightedUnion(unionFind, group1, group2);
                    num--;
                } while(!islands.empty());
                unionFind[idx] = group1;
                unionFind[group1]--;
            }
            result.push_back(num);
        }
        return result;
    }
};

int main() {
	int m = 3, n = 3;
	pair<int, int> p[] = {make_pair(0, 0), make_pair(0, 1), make_pair(1, 2), make_pair(2, 1),};
	vector<pair<int, int> > positions(p,p+4);
	Solution s;
	vector<int> res = s.numIslands2(m, n, positions);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}