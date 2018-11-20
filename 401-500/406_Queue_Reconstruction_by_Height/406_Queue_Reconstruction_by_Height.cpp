#include <vector>
#include <iostream>
using namespace std;

bool myComp(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
}

class Solution {
public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
        sort(people.begin(), people.end(), myComp);
        vector<pair<int, int> > result;
        for(int i = 0; i < people.size(); i++) {
            result.insert(result.begin() + people[i].second, people[i]);
        }
        return result;
    }
};

int main() {
	Solution s;
	pair<int, int> p[] = {make_pair(7, 0), make_pair(4, 4), make_pair(7, 1), make_pair(5, 0), make_pair(6, 1), make_pair(5, 2)};
	vector<pair<int, int> > people(p, p + 6);
	vector<pair<int, int> > res = s.reconstructQueue(people);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i].first << ',' << res[i].second << ' ';
	}
	cout << endl;
	return 0;
}