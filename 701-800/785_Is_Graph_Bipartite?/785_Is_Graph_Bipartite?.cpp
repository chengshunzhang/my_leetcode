#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int> >& graph) {
        if(graph.empty()) {
            return true;
        }
        vector<int> unionFind(graph.size(), -1);
        vector<bool> visited(graph.size(), false);
        int set1, set2;
        queue<int> q;
        for(int i = 0; i < graph.size(); i++) {
            if(graph[i].empty() || visited[i]) {
                continue;
            }
            set1 = i;
            set2 = graph[i][0];
            unionFind[set1] = set1;
            unionFind[set2] = set2;
            visited[set1] = visited[set2] = true;
            q.push(graph[i][0]);
            for(int j = 1; j < graph[i].size(); j++) {
                unionFind[graph[i][j]] = set2;
                visited[graph[i][j]] = true;
                q.push(graph[i][j]);
            }
            while(!q.empty()) {
                int curNode = q.front();
                q.pop();
                for(int j = 0; j < graph[curNode].size(); j++) {
                    if(unionFind[curNode] == unionFind[graph[curNode][j]]) {
                        return false;
                    } else if(unionFind[graph[curNode][j]] == -1) {
                        unionFind[graph[curNode][j]] = unionFind[curNode] == set1 ? set2 : set1;
                        visited[graph[curNode][j]] = true;
                        q.push(graph[curNode][j]);
                    }
                }
            }
        }
        return true;
    }
};

int main() {
	vector<vector<int> > graph(4, vector<int> (4));
	graph[0][0] = 1;graph[0][1] = 3;
	graph[1][0] = 0;graph[1][1] = 2;
	graph[2][0] = 1;graph[2][1] = 3;
	graph[3][0] = 0;graph[3][1] = 2;
	Solution s;
	cout << s.isBipartite(graph) << endl;
	return 0;
}