#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
private:
    void BFS(vector<vector<int> >& graph, vector<bool>& visited, int start) {
        int n = graph.size();
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int> >& M) {
        int n = M.size(), groups = 0;
        vector<vector<int> > graph(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && M[i][j] == 1) {
                    graph[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                BFS(graph, visited, i);
                groups++;
            }
        }
        return groups;
    }
};

int main() {
	vector<vector<int> > M(3, vector<int> (3, 1));
	M[0][2] = M[1][2] = M[2][0] = M[2][1] = 0;
	Solution s;
	cout << s.findCircleNum(M) << endl;
	return 0;
}