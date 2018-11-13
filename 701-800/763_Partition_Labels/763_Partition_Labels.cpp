#include <set>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        if(S.empty()) {
            return result;
        }
        unordered_map<char, pair<int, int> > hash;
        set<pair<int, int> > interval;
        for(int i = 0; i < S.size(); i++) {
            if(hash.count(S[i])) {
                hash[S[i]].second = i;
            } else {
                hash[S[i]] = make_pair(i, i);
            }
        }
        for(unordered_map<char, pair<int, int> >::iterator it = hash.begin(); it != hash.end(); it++) {
            interval.insert(it -> second);
        }
        int curStart = (*interval.begin()).first, curEnd = (*interval.begin()).second;
        interval.erase(interval.begin());
        while(!interval.empty()) {
            int start = (*interval.begin()).first, end = (*interval.begin()).second;
            interval.erase(interval.begin());
            if(start < curEnd) {
                if(end > curEnd) {
                    curEnd = end;
                }
            } else {
                result.push_back(curEnd - curStart + 1);
                curStart = start;
                curEnd = end;
            }
            if(curEnd == S.size() - 1) {
                result.push_back(curEnd - curStart + 1);
                break;
            }
        }
        return result;
    }
};

int main() {
	string S("ababcbacadefegdehijhklij");
	Solution s;
	vector<int> res = s.partitionLabels(S);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}