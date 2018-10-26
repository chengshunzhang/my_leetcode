#include <vector>
#include <iostream>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool comp(Interval i1, Interval i2) {
    return i1.start < i2.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty()) {
            return result;
        }
        sort(intervals.begin(), intervals.end(), comp);
        for(int i = 0; i < intervals.size(); i++) {
            if(result.empty() || intervals[i].start > result.back().end) {
                result.push_back(intervals[i]);
            } else if(intervals[i].end > result.back().end) {
                result.back().end = intervals[i].end;
            }
        }
        return result;
    }
};

int main() {
	Solution s;
	vector<Interval> intervals;
	intervals.push_back(Interval(1,3));
	intervals.push_back(Interval(2,6));
	intervals.push_back(Interval(8,10));
	intervals.push_back(Interval(15,18));
	vector<Interval> res = s.merge(intervals);
	for(int i = 0; i < res.size(); i++) {
		cout << '[' << res[i].start << ',' << res[i].end << "] ";
	}
	cout << endl;
	return 0;
}