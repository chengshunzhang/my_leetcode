#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) {
            return 0;
        }
        if(heights.size() == 1) {
            return heights[0];
        }
        heights.push_back(0);
        int maxArea = 0;
        stack<pair<int, int> > st;
        st.push(make_pair(1, heights[0]));
        for(int i = 1; i < heights.size(); i++) {
            if(st.top().second >= heights[i]) {
                int width = 0;
                do {
                    int area = st.top().second * (st.top().first + width);
                    width += st.top().first;
                    st.pop();
                    if(area > maxArea) {
                        maxArea = area;
                    }
                } while(!st.empty() && st.top().second >= heights[i]);
                st.push(make_pair(width + 1, heights[i]));
            } else {
               st.push(make_pair(1, heights[i])); 
            }
        }
        return maxArea;
    }
};

int main() {
	int n[] = {2,1,5,6,2,3};
	vector<int> nums(n,n+6);
	Solution s;
	cout << s.largestRectangleArea(nums) << endl;
	return 0;
}