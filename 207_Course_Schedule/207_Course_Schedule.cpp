#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> count(numCourses, 0);
        vector<vector<int> > graph(numCourses);
        int top = -1;
        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
            count[prerequisites[i].first]++;
        }
        for(int i = 0; i < count.size(); i++) {
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
                	count[graph[v][j]]--;
                    if(count[graph[v][j]] == 0) {
                        count[graph[v][j]] = top;
                        top = graph[v][j];
                    }
                }
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
	Solution s;
	int num = 3;
	vector<pair<int, int> > pre;
	pre.push_back(pair<int, int> (1,0));pre.push_back(pair<int, int> (1,2));pre.push_back(pair<int, int> (0,1));
	cout << s.canFinish(num, pre) << endl;
	return 0;
}