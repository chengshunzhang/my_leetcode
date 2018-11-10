#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int width1 = rec1[2] - rec1[0], width2 = rec2[2] - rec2[0], height1 = rec1[3] - rec1[1], height2 = rec2[3] - rec2[1];
        return rec1[2] > rec2[0] && rec2[2] > rec1[0] && rec1[3] > rec2[1] && rec2[3] > rec1[1];
    }
};

int main() {
	int n1[] = {0,0,2,2}, n2[] = {1,1,3,3};
	vector<int> rec1(n1,n1+4), rec2(n2,n2+4);
	Solution s;
	cout << s.isRectangleOverlap(rec1, rec2) << endl;
	return 0;
}