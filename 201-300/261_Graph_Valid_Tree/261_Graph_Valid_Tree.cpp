#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int findRoot(vector<int>& uf, int x) {
        while(uf[x] >= 0) {
            x = uf[x];
        }
        return x;
    }
    void weightedUnion(vector<int>& uf, int x, int y) {
        if(uf[x] > uf[y]) {
            uf[y] += uf[x];
            uf[x] = y;
        } else {
            uf[x] += uf[y];
            uf[y] = x;
        }
    }
public:
    bool validTree(int n, vector<pair<int, int> >& edges) {
        vector<int> uf(n, -1);
        int groups = n;
        for(int i = 0; i < edges.size(); i++) {
            int group1 = findRoot(uf, edges[i].first), group2 = findRoot(uf, edges[i].second);
            if(group1 == group2) {
                return false;
            }
            weightedUnion(uf, group1, group2);
            groups--;
        }
        return groups == 1;
    }
};

int main() {
	pair<int, int> e[] = {make_pair(0, 1), make_pair(0, 2), make_pair(0, 3), make_pair(1, 4)};
	vector<pair<int, int> > edges(e,e+4);
	Solution s;
	int n = 5;
	cout << s.validTree(n, edges) << endl;
	return 0;
}