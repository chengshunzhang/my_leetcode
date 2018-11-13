#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int K) {
        vector<vector<pair<int, int> > > graph(n);
        vector<vector<int> > dp(K + 2, vector<int> (n));
        for(int i = 0; i < flights.size(); i++) {
            graph[flights[i][1]].push_back(make_pair(flights[i][0], flights[i][2]));
        }
        for(int i = 0; i < n; i++) {
            dp[0][i] = ((uint)1 << 31) - 1;
        }
        dp[0][src] = 0;
        for(int i = 1; i < K + 2; i++) {
            for(int j = 0; j < n; j++) {
                int candidate1 = dp[i - 1][j], candidate2 = ((uint)1 << 31) - 1;
                for(int u = 0; u < graph[j].size(); u++) {
                    if(dp[i - 1][graph[j][u].first] != ((uint)1 << 31) - 1 && dp[i - 1][graph[j][u].first] + graph[j][u].second < candidate2) {
                        candidate2 = dp[i - 1][graph[j][u].first] + graph[j][u].second;
                    }
                }
                dp[i][j] = min(candidate1, candidate2);
            }
        }
        if(dp[K + 1][dst] == ((uint)1 << 31) - 1) {
            return -1;
        }
        return dp[K + 1][dst];
    }
};

int main() {
	int n = 3, src = 0, dst = 2, k = 1;
	vector<vector<int> > edges(3, vector<int> (3));
	edges[0][0] = 0; edges[0][1] = 1; edges[0][2] = 100;
	edges[1][0] = 1; edges[1][1] = 2; edges[1][2] = 100;
	edges[2][0] = 0; edges[2][1] = 2; edges[2][2] = 500;
	Solution s;
	cout << s.findCheapestPrice(n, edges, src, dst, k) << endl;
	return 0;
}