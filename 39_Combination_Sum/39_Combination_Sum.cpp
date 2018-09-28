#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void sumHelper(vector<vector<int> >& result, vector<int>& temp, vector<int>& candidates, int pos, int sum, int& target) {
        for(int i = pos; i < candidates.size(); i++) {
            sum += candidates[i];
            if(sum == target) {
                temp.push_back(candidates[i]);
                result.push_back(temp);
            } else if(sum > target) {
                break;
            } else {
                temp.push_back(candidates[i]);
                sumHelper(result, temp, candidates, i, sum, target);   
            }
            sum -= candidates[i];
            temp.pop_back();
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> temp;
        sumHelper(result, temp, candidates, 0, 0, target);
        return result;
    }
};

int main() {
	int c[] = {2,3,6,7}, target = 7;
	vector<int> candidates(c,c+4);
	Solution s;
	vector<vector<int> > res = s.combinationSum(candidates, target);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << ' ';
		cout << endl;
	}
	return 0;
}