#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        if(x <= arr[0]) {
            result.assign(arr.begin(), arr.begin() + k);
        } else if(x >= arr.back()) {
            result.assign(arr.end() - k, arr.end());
        } else {
            int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            int left = right - 1;
            for(int i = 0; i < k; i++) {
                if((left >= 0 && x - arr[left] <= arr[right] - x) || right == arr.size()) {
                    left--;
                } else {
                    right++;
                }
            }
            for(int i = left + 1; i < right; i++) {
                result.push_back(arr[i]);
            }
        }
        return result;
    }
};

int main() {
	int k = 4, x = 3;
	int n[] = {1,2,3,4,5};
	vector<int> arr(n,n+5);
	Solution s;
	vector<int> res = s.findClosestElements(arr, k, x);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}