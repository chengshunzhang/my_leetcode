#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int partition(vector<string>& numsStr, int left, int right) {
        int pivotpos = left;
        for(int j = left + 1; j <= right; j++) {
            string s1 = numsStr[j] + numsStr[left];
            string s2 = numsStr[left] + numsStr[j];
            if(s1 < s2) {
                pivotpos++;
                if(pivotpos != j) {
                    string temp = numsStr[pivotpos];
                    numsStr[pivotpos] = numsStr[j];
                    numsStr[j] = temp;
                }
            }
        }
        if(pivotpos != left) {
            string temp = numsStr[pivotpos];
            numsStr[pivotpos] = numsStr[left];
            numsStr[left] = temp;
        }
        return pivotpos;
    }
    void quickSort(vector<string>& numsStr, int left, int right) {
        if(left >= right) {
            return;
        }
        int pivot = partition(numsStr, left, right);
        quickSort(numsStr, left, pivot - 1);
        quickSort(numsStr, pivot + 1, right);
    }
public:
    string largestNumber(vector<int>& nums) {
        if(nums.empty()) {
            return "";
        }
        int n = nums.size();
        vector<string> numsStr(n);
        string result;
        for(int i = 0; i < n; i++) {
            numsStr[i] = to_string(nums[i]);
        }
        quickSort(numsStr, 0, n - 1);
        for(int i = n - 1; i >= 0; i--) {
            result.append(numsStr[i]);
        }
        if(atoi(result.c_str()) == 0) {
            return "0";
        } else {
            return result;
        }
    }
};

int main() {
	int n[] = {23,9,90,5};
	Solution s;
	vector<int> nums(n,n+4);
	cout << s.largestNumber(nums) << endl;
	return 0;
}