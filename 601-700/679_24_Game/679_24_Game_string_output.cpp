#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
private:
    bool helper(vector<double> nums, vector<string>& way) {
        if(nums.size() == 1) {
            return fabs(nums[0] - 24) < 1e-6;
        }
        for(int i = 0; i + 1 < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                double first = (double)nums[i], second = (double)nums[j];
                string sFirst = way[i], sSecond = way[j];
                nums.erase(nums.begin() + j);
                nums.erase(nums.begin() + i);
                way.erase(way.begin() + j);
                way.erase(way.begin() + i);
                double n[] = {(double)first + second, (double)first * second, (double)first - second, (double)second - first};
                string w[] = {"(" + sFirst + "+" + sSecond + ")", "(" + sFirst + "*" + sSecond + ")", "(" + sFirst + "-" + sSecond + ")", "(" + sSecond + "-" + sFirst + ")"};
                vector<double> newNums(n, n + 4);
                vector<string> newStrs(w, w + 4);
                if(fabs(second) > 1e-6) {
                    newNums.push_back((double)first / second);
                    newStrs.push_back("(" + sFirst + "/" + sSecond + ")");
                }
                if(fabs(first) > 1e-6) {
                    newNums.push_back((double)second / first);
                    newStrs.push_back("(" + sSecond + "/" + sFirst + ")");
                }
                for(int k = 0; k < newNums.size(); k++) {
                    nums.push_back(newNums[k]);
                    way.push_back(newStrs[k]);
                    if(helper(nums, way)) {
                        return true;
                    }
                    nums.pop_back();
                    way.pop_back();
                }
                nums.insert(nums.begin() + i, first);
                nums.insert(nums.begin() + j, second);
                way.insert(way.begin() + i, sFirst);
                way.insert(way.begin() + j, sSecond);
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> ns(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            ns[i] = (double)nums[i];
        }
        vector<string> way(4);
        for(int i = 0; i < way.size(); i++) {
            way[i] = to_string(nums[i]);
        }
        bool result = helper(ns, way);
        cout << way[0] << endl;
        return result;
    }
};

int main() {
	int n[] = {4,1,8,7};
	vector<int> nums(n, n+4);
	Solution s;
	cout << s.judgePoint24(nums) << endl;
	return 0;
}