#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int max = (height[left] > height[right]) ? height[right] * (right - left) : height[left] * (right - left);
		while (left < right) {
			if (height[left] < height[right])
				left++;
			else
				right--;
			int temp = (height[left] > height[right]) ? height[right] * (right - left) : height[left] * (right - left);
			if (temp > max)
				max = temp;
		}
		return max;
	}
};

int main(){
	int h[] = {6,4,3,1,4,6,99,62,1,2,6};
    vector<int> height(h,h+11);
    Solution s;
    cout << s.maxArea(height) << endl;
	return 0;
}