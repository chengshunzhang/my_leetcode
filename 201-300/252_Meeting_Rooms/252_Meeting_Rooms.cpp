#include <vector>
#include <iostream>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool myComp(Interval& itv1, Interval& itv2) {
    return itv1.start < itv2.start;
}
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()) {
            return true;
        }
        sort(intervals.begin(), intervals.end(), myComp);
        for(int i = 0; i + 1 < intervals.size(); i++) {
            if(intervals[i + 1].start < intervals[i].end) {
                return false;
            }
        }
        return true;
    }
};

int main() {
	Interval its[] = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
	vector<Interval> intervals(its,its+3);
	Solution s;
	cout << s.canAttendMeetings(intervals) << endl;
	return 0;
}