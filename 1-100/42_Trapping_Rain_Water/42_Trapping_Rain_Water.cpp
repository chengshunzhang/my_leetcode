#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), result = 0;
        int left = 0, right = n - 1, temp;
        while(left < right) {
            if(height[left] <= height[right]) {
                temp = left + 1;
                while(height[temp] < height[left]) {
                    result += height[left] - height[temp];
                    temp++;
                }
                left = temp;
            } else {
                temp = right - 1;
                while(height[temp] < height[right]) {
                    result += height[right] - height[temp];
                    temp--;
                }
                right = temp;
            }
        }
        return result;
    }
};

int main() {
	int h[] = {5,2,1,5};
	vector<int> height(h, h + 4);
	Solution s;
	cout << s.trap(height) << endl;
	return 0;
}