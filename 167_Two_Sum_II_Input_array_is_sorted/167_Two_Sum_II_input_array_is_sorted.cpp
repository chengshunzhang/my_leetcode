#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2);
        unordered_map<int, int> m;
        for(int i = 0; i < numbers.size(); i++) {
            m[numbers[i]] = i;
        }
        for(int i = 0; i < numbers.size(); i++) {
            int need = target - numbers[i];
            unordered_map<int, int>::iterator it = m.find(need);
            if(it != m.end()) {
                result[0] = i + 1;
                result[1] = it -> second + 1;
                return result;
            }
        }
    }
};

int main() {
    int n[] = {2,7,11,15}, target = 9;
    vector<int> nums(n,n+4);
    Solution s;
    vector<int> res = s.twoSum(nums, target);
    cout << res[0] << "  " << res[1] << endl;
    return 0;
}