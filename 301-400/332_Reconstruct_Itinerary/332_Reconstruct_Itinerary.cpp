#include <unordered_map>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        vector<string> result;
        unordered_map<string, multiset<string> > hash;
        for(int i = 0; i < tickets.size(); i++) {
            hash[tickets[i].first].insert(tickets[i].second);
        }
        stack<string> st;
        st.push("JFK");
        while(!st.empty()) {
            string temp = st.top();
            if(!hash.count(temp) || hash[temp].empty()) {
                result.push_back(temp);
                st.pop();
            } else {
                st.push(*hash[temp].begin());
                hash[temp].erase(hash[temp].begin());
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
	pair<string, string> t[] = {make_pair("JFK", "SFO"), make_pair("JFK", "ATL"), make_pair("SFO", "ATL"), make_pair("ATL", "JFK"), make_pair("ATL", "SFO")};
	vector<pair<string, string> > tickets(t, t + 5);
	Solution s;
	vector<string> res = s.findItinerary(tickets);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ',';
	}
	cout << endl;
	return 0;
}