#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int find(vector<int>& parent, int x) {
        while(parent[x] >= 0) {
            x = parent[x];
        }
        return x;
    }
    
    void weightedUnion(vector<int>& parent, int p1, int p2) {
        if(parent[p1] < parent[p2]) {
            parent[p1] += parent[p2];
            parent[p2] = p1;
        } else {
            parent[p2] += parent[p1];
            parent[p1] = p2;
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, -1);
        int result = 0;
        for(vector<int> edge : edges) {
            int parent1 = find(parent, edge[0]), parent2 = find(parent, edge[1]);
            if(parent1 != parent2) {
                weightedUnion(parent, parent1, parent2);
            }
        }
        for(int i = 0; i < n; i++) {
            if(parent[i] < 0) {
                result++;
            }
        }
        return result;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    Solution sol;
    cout << sol.countComponents(n, edges) << endl;
    return 0;
}