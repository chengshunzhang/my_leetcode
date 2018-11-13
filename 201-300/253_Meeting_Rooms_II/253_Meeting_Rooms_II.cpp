#include <vector>
#include <iostream>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool myComp(Interval interval1, Interval interval2) {
    return interval1.start < interval2.start;
}
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), myComp);
        vector<vector<Interval> > rooms(1, vector<Interval> (1, intervals[0]));
        for(int i = 1; i < intervals.size(); i++) {
            bool fit = false;
            for(int j = 0; j < rooms.size(); j++) {
                if(intervals[i].start >= rooms[j][rooms[j].size() - 1].end) {
                    rooms[j].push_back(intervals[i]);
                    fit = true;
                    break;
                }
            }
            if(!fit) {
                rooms.push_back(vector<Interval> (1, intervals[i]));
            }
        }
        return rooms.size();
    }
};

int main() {
	Solution s;
	vector<Interval> intervals;
	intervals.push_back(Interval(0, 30));
	intervals.push_back(Interval(5, 10));
	intervals.push_back(Interval(15, 20));
	cout << s.minMeetingRooms(intervals) << endl;
	return 0;
}