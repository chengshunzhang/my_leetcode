#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool> hash;
        unordered_map<string, bool> visited;
        for(int i = 0; i < bank.size(); i++) {
            hash[bank[i]] = true;
        }
        if(!hash.count(end)) {
            return -1;
        }
        char genes[] = {'A', 'G', 'C', 'T'};
        queue<string> q;
        int count = 1;
        q.push(start);
        q.push("");
        visited[start] = true;
        while(q.size() > 1) {
            string temp = q.front();
            q.pop();
            if(temp == "") {
                count++;
                q.push("");
            } else {
                for(int i = 0; i < 8; i++) {
                    for(int j = 0; j < 4; j++) {
                        if(genes[j] != temp[i]) {
                            string newGene(temp);
                            newGene[i] = genes[j];
                            if(newGene == end) {
                                return count;
                            }
                            if(!visited.count(newGene) && hash.count(newGene)) {
                                q.push(newGene);
                                visited[newGene] = true;
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
	string start = "AACCGGTT", end = "AACCGGTA";
	string b[] = {"AACCGGTA"};
	vector<string> bank(b, b + 1);
	Solution s;
	cout << s.minMutation(start, end, bank) << endl;
	return 0;
}