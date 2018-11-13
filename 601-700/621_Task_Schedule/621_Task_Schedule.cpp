#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> tasksNum(26, 0);
        for(int i = 0; i < len; i++) {
            int num = tasks[i] - 'A';
            tasksNum[num]++;
        }
        sort(tasksNum.begin(), tasksNum.end());
        int idx = 24;
        while(idx > - 1 && tasksNum[idx] == tasksNum[idx + 1]) {
            idx--;
        }
        int lenCal = (tasksNum[25] - 1) * n + tasksNum[25] + (25 - idx - 1);
        return len > lenCal ? len : lenCal;
    }
};

int main() {
	char t[] = {'A','A','A','B','B','B'};
	int n = 2;
	vector<char> tasks(t,t+6);
	Solution s;
	cout << s.leastInterval(tasks, n) << endl;
	return 0;
}