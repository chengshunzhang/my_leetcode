#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> result;
        vector<int> count(numCourses, 0);
        vector<vector<int> > graph(numCourses);
        int top = -1;
        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
            count[prerequisites[i].first]++;
        }
        for(int i = 0; i < numCourses; i++) {
            if(count[i] == 0) {
                count[i] = top;
                top = i;
            }
        }
        for(int i = 0; i < numCourses; i++) {
            if(top != -1) {
                int v = top;
                top = count[top];
                for(int j = 0; j < graph[v].size(); j++) {
                    if(--count[graph[v][j]] == 0) {
                        count[graph[v][j]] = top;
                        top = graph[v][j];
                    }
                }
                result.push_back(v);
            } else {
                return vector<int> ();
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	vector<pair<int, int> > pre;
	pre.push_back(pair<int, int> (1, 0));
	int num = 2;
	vector<int> result = s.findOrder(num, pre);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	cout << endl;
	return 0;
}