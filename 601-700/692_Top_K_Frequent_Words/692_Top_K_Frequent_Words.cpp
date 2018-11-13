#include <queue>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

struct comp {
    bool operator()(pair<string, int> p1, pair<string, int> p2) {
        return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result(k);
        priority_queue<pair<string, int>, vector<pair<string, int> >, comp > heap;
        unordered_map<string, int> hash;
        for(int i = 0; i < words.size(); i++) {
            hash[words[i]]++;
        }
        for(unordered_map<string, int>::iterator it = hash.begin(); it != hash.end(); it++) {
            if(heap.size() < k) {
                heap.push(make_pair(it -> first, it -> second));
            } else {
                if(it -> second > heap.top().second || (it -> second == heap.top().second && it -> first < heap.top().first)) {
                    heap.pop();
                    heap.push(make_pair(it -> first, it -> second));
                }
            }
        }
        for(int i = k - 1; i >= 0; i--) {
            result[i] = heap.top().first;
            heap.pop();
        }
        return result;
    }
};

int main() {
	vector<string> words;
	words.push_back("i");
	words.push_back("love");
	words.push_back("leetcode");
	words.push_back("i");
	words.push_back("love");
	words.push_back("coding");
	Solution s;
	vector<string> res = s.topKFrequent(words, 2);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}