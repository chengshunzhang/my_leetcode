#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
private:
    void killHelper(unordered_map<int, vector<int> >& hash, vector<int>& result, int cur) {
        result.push_back(cur);
        vector<int> children = hash[cur];
        for(int i = 0; i < children.size(); i++) {
            killHelper(hash, result, children[i]);
        }
    }
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int> > hash;
        for(int i = 0; i < pid.size(); i++) {
            hash[ppid[i]].push_back(pid[i]);
        }
        vector<int> result;
        killHelper(hash, result, kill);
        return result;
    }
};

int main() {
	int p[] = {1, 3, 10, 5}, pp[] = {3, 0, 5, 3}, kill = 5;
	vector<int> pid(p, p + 4), ppid(pp, pp + 4);
	Solution s;
	vector<int> res = s.killProcess(pid, ppid, kill);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}