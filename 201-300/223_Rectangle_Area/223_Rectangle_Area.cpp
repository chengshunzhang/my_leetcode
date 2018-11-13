#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = (C - A) * (D - B), s2 = (G - E) * (H - F);
        int intersect = min(min(max(G - A, 0), max(C - E, 0)), min(C - A, G - E)) * min(min(max(H - B, 0), max(D - F, 0)), min(H - F, D - B));
        return s1 + s2 - intersect;
    }
};

int main() {
	Solution s;
	cout << s.computeArea(-3,0,3,4,0,-1,9,2) << endl;
	return 0;
}