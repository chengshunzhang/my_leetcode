#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int, int> > verticalLines;
        vector<pair<int, int> > result;
        for(int i = 0; i < buildings.size(); i++) {
            verticalLines.push_back(pair<int, int> (buildings[i][0], -buildings[i][2]));
            verticalLines.push_back(pair<int, int> (buildings[i][1], buildings[i][2]));
        }
        sort(verticalLines.begin(), verticalLines.end());
        multiset<int, greater<int> > ms;
        for(int i = 0; i < verticalLines.size(); i++) {
            pair<int, int> p(verticalLines[i].first, -verticalLines[i].second);
            if(ms.empty()) {
                result.push_back(p);
                ms.insert(-verticalLines[i].second);
            } else {
                if(verticalLines[i].second < 0) {
                    if(-verticalLines[i].second > *ms.begin()) {
                        result.push_back(p);
                    }
                    ms.insert(-verticalLines[i].second);
                } else {
                    ms.erase(ms.find(verticalLines[i].second));
                    if(ms.empty()) {
                        result.push_back(pair<int, int> (verticalLines[i].first, 0));
                    } else if(*ms.begin() < verticalLines[i].second) {
                        result.push_back(pair<int, int> (verticalLines[i].first, *ms.begin()));
                    }
                }
            }
        }
        return result;
    }
};

int main() {
	vector<vector<int> > buildings(5, vector<int> (3));
	buildings[0][0] = 2;buildings[0][1] = 9;buildings[0][2] = 10;
	buildings[1][0] = 3;buildings[1][1] = 7;buildings[1][2] = 15;
	buildings[2][0] = 5;buildings[2][1] = 12;buildings[2][2] = 12;
	buildings[3][0] = 15;buildings[3][1] = 20;buildings[3][2] = 10;
	buildings[4][0] = 19;buildings[4][1] = 24;buildings[4][2] = 8;
	Solution s;
	vector<pair<int, int> > res = s.getSkyline(buildings);
	for(int i = 0; i < res.size(); i++) {
		cout << '(' << res[i].first << ',' << res[i].second << ')' << ' ';
	}
	cout << endl;
	return 0;
}