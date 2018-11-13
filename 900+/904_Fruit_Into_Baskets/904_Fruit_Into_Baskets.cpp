#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int result = -1, start = 0, num = 1, first = tree[0], second = -1;
        for(int i = 1; i < tree.size(); i++) {
            if(tree[i] == first || tree[i] == second) {
                num++;
                if(tree[i] != tree[i - 1]) {
                    start = i;
                }
                continue;
            }
            if(second == -1) {
                num++;
                second = tree[i];
                start = i;
                continue;
            }
            first = tree[start];
            second =  tree[i];
            if(num > result) {
                result = num;
            }
            num = i - start + 1;
            start = i;
        }
        return num > result ? num : result;
    }
};

int main() {
	int t[] = {1,2,1};
	vector<int> tree(t,t+3);
	Solution s;
	cout << s.totalFruit(tree) << endl;
	return 0;
}