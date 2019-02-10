#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int max = min(height[left], height[right]) * (right - left);
		while(left < right) {
			if(height[left] < height[right]) {
                left++;
            } else {
               right--; 
            }
			int temp = min(height[left], height[right]) * (right - left);
			if(temp > max) {
                max = temp;
            }	
		}
        return max;
    }
};

int main(){
	vector<int> height = {6,4,3,1,4,6,99,62,1,2,6};
    Solution s;
    cout << s.maxArea(height) << endl;
	return 0;
}