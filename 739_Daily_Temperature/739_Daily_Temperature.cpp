#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        if(T.empty()) {
            return result;
        }
        stack<pair<int, int> > st;
        st.push(make_pair(0, T[0]));
        for(int i = 1; i < T.size(); i++) {
            if(T[i] > st.top().second) {
                do {
                    pair<int, int> temp = st.top();
                    st.pop();
                    result[temp.first] = i - temp.first;
                } while(!st.empty() && T[i] > st.top().second);
            }
            st.push(make_pair(i, T[i]));
        }
        return result;
    }
};

int main() {
	int n[] = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> nums(n,n+8);
	Solution s;
	vector<int> res = s.dailyTemperatures(nums);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}