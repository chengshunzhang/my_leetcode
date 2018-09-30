#include <vector>
#include <iostream>
using namespace std;

class Solution {
    private:
    void combineHelper(vector<vector<int> >& result, vector<int>& temp, int& k, int& n, int pos) {
        if(temp.size() == k) {
            result.push_back(temp);
            return;
        }
        for(int i = pos; i <= n; i++) {
            temp.push_back(i);
            combineHelper(result, temp, k, n, i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> temp;
        combineHelper(result, temp, k, n, 1);
        return result;
    }
};

int main() {
	Solution s;
	vector<vector<int> > res = s.combine(4,2);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}