#include <vector>
#include <iostream>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        int i = 0, j = 0;
        vector<Interval> result;
        while(i < A.size() && j < B.size()) {
            if(A[i].end < B[j].start) {
                i++;
            } else if(A[i].start > B[j].end) {
                j++;
            } else if(A[i].end < B[j].end) {
                result.push_back(Interval(max(A[i].start, B[j].start), A[i].end));
                i++;
            } else {
                result.push_back(Interval(max(A[i].start, B[j].start), B[j].end));
                j++;
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	vector<Interval> A = {Interval(0, 2), Interval(5, 10), Interval(13, 23), Interval(24, 25)};
	vector<Interval> B = {Interval(1, 5), Interval(8, 12), Interval(15, 24), Interval(25, 26)};
	vector<Interval> res = s.intervalIntersection(A, B);
	for(Interval itv : res) {
		cout << '[' << itv.start << ',' << itv.end << ']' << ' ';
	}
	cout << endl;
	return 0;
}