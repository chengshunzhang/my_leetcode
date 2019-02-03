#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    bool isEqual(vector<int>& arr1, vector<int>& arr2) {
        for(int i = 0; i < arr1.size(); i++) {
            if(arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }    
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> cur, pre;
        cur.assign(cells.begin(), cells.end());
        cur[0] = 0;
        cur[7] = 0;
        for(int i = 1; i < 7; i++) {
            if((cells[i- 1] ^ cells[i + 1]) == 0) {
                cur[i] = 1;
            } else {
                cur[i] = 0;
            }
        }
        vector<vector<int>> status(1, cur);
        int curDay = 1;
        while(curDay < N) {
            pre.assign(cur.begin(), cur.end());
            for(int i = 1; i < 7; i++) {
                if((pre[i- 1] ^ pre[i + 1]) == 0) {
                    cur[i] = 1;
                } else {
                    cur[i] = 0;
                }
            }
            if(isEqual(cur, status[0])) {
                break;
            }
            curDay++;
            status.push_back(cur);
        }
        if(curDay == N) {
            return status.back();
        }
        return status[(N - 1) % curDay];
    }
};

int main() {
	vector<int> cells = {1,0,0,1,0,0,1,0};
	int N = 1000000000;
	Solution s;
	vector<int> res = s.prisonAfterNDays(cells, N);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ',';
	}
	cout << "\b \b\n";
	return 0;
}