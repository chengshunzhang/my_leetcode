#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    string topologicalSort(vector<int>& inDegree, vector<vector<int> >& graph, int nodes) {
        int top = -1;
        string result = "";
        for(int i = 0; i < 26; i++) {
            if(inDegree[i] == 0) {
                inDegree[i] = top;
                top = i;
            }
        }
        for(int i = 0; i < nodes; i++) {
            if(top == -1) {
                return "";
            }
            int j = top;
            top = inDegree[top];
            result.push_back(j + 'a');
            for(int m = 0; m < graph[j].size(); m++) {
                int v = graph[j][m];
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    inDegree[v] = top;
                    top = v;
                }
            }
        }
        return result;
    }
public:
    string alienOrder(vector<string>& words) {
        if(words.empty()) {
            return "";
        }
        if(words.size() == 1) {
            return words[0];
        }
        vector<int> inDegree(26, -1);
        vector<vector<int> > graph(26);
        string pre = words[0];
        int numOfChars = 0;
        for(int i = 0; i < pre.size(); i++) {
            if(inDegree[pre[i] - 'a'] == -1) {
                inDegree[pre[i] - 'a']++;
                numOfChars++;
            }
        }
        for(int i = 1; i < words.size(); i++) {
            string cur = words[i];
            int pos = 0;
            while(pos < pre.size() && pre[pos] == cur[pos]) {
                pos++;
            }
            if(pos != pre.size()) {
                graph[pre[pos] - 'a'].push_back(cur[pos] - 'a');
                if(inDegree[cur[pos] - 'a'] == -1) {
                    inDegree[cur[pos] - 'a'] = 1;
                    numOfChars++;
                } else {
                    inDegree[cur[pos] - 'a']++;
                }
                pos++;
            }
            if(numOfChars < 26) {
                while(pos < cur.size()) {
                    if(inDegree[cur[pos] - 'a'] == -1) {
                        inDegree[cur[pos] - 'a']++;
                        numOfChars++;
                    }
                    pos++;
                }
            }
            pre = cur;
        }
        return topologicalSort(inDegree, graph, numOfChars);
    }
};

int main() {
	Solution s;
	string w[] = {"aac", "aabb", "aaba"};
	vector<string> words(w,w+3);
	cout << s.alienOrder(words) << endl;
	return 0;
}