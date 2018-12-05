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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int n = intervals.size();
        vector<int> begins(n), ends(n);
        for(int i = 0; i < n; i++) {
            begins[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }
        int left = upper_bound(begins.begin(), begins.end(), newInterval.start) - begins.begin();
        int right = upper_bound(ends.begin(), ends.end(), newInterval.end) - ends.begin();
        if(left > 0 && intervals[left - 1].end >= newInterval.start) {
            left--;
            newInterval.start = intervals[left].start;
        }
        for(int i = 0; i < left; i++) {
            result.push_back(intervals[i]);
        }
        if(right < n && intervals[right].start <= newInterval.end) {
            newInterval.end = intervals[right].end;
            right++;
        }
        result.push_back(newInterval);
        for(int i = right; i < n; i++) {
            result.push_back(intervals[i]);
        }
        return result;
    }
};

int main() {
	Interval is[] = {Interval(1, 3), Interval(6, 9)};
	vector<Interval> intervals(is, is + 2);
	Solution s;
	Interval nI(2, 5);
	vector<Interval> res = s.insert(intervals, nI);
	for(int i = 0; i < res.size(); i++) {
		cout << '[' << res[i].start << ',' << res[i].end << ']' << ' ';
	}
	cout << endl;
	return 0;
}