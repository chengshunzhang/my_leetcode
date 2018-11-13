#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void sumHelper(vector<vector<int> >& result, vector<int>& candidates, vector<int>& temp, int target, int pos, int sum) {
        for(int i = pos; i < candidates.size();) {
            sum += candidates[i];
            if(sum == target) {
                temp.push_back(candidates[i]);
                result.push_back(temp);
                temp.pop_back();
                break;
            } else if(sum < target) {
                temp.push_back(candidates[i]);
                sumHelper(result, candidates, temp, target, i + 1, sum);
                sum -= candidates[i];
                temp.pop_back();
            } else {
                break;
            }
            i++;
            while(i < candidates.size() && candidates[i] == candidates[i - 1]) {
                i++;
            }
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        sumHelper(result, candidates, temp, target, 0, 0);
        return result;
    }
};

int main() {
    Solution s;
    int c[] = {10,1,2,7,6,1,5}, target = 8;
    vector<int> candidates(c, c + 7);
    vector<vector<int> > res = s.combinationSum2(candidates, target);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}