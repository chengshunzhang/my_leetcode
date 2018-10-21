#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) : label(x) {}
};

class Solution {
private:
    void cloneHelper(UndirectedGraphNode*& res, UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*>& hashMap) {
        for(int i = 0; i < node -> neighbors.size(); i++) {
            if(hashMap.count(node -> neighbors[i] -> label)) {
                res -> neighbors.push_back(hashMap[node -> neighbors[i] -> label]);
            } else {
                res -> neighbors.push_back(new UndirectedGraphNode(node -> neighbors[i] -> label));
                hashMap[node -> neighbors[i] -> label] = res -> neighbors.back();
                cloneHelper(res -> neighbors.back(), node -> neighbors[i], hashMap);
            }
        }
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) {
            return NULL;
        }
        unordered_map<int, UndirectedGraphNode*> hashMap;
        UndirectedGraphNode* result = new UndirectedGraphNode(node -> label);
        hashMap[node -> label] = result;
        cloneHelper(result, node, hashMap);
        return result;
    }
};

int main() {
	UndirectedGraphNode* start = new UndirectedGraphNode(0);
	start -> neighbors.push_back(new UndirectedGraphNode(1));
	start -> neighbors.push_back(new UndirectedGraphNode(2));
	start -> neighbors[0] -> neighbors.push_back(start -> neighbors[1]);
	start -> neighbors[1] -> neighbors.push_back(start -> neighbors[1]);
	Solution s;
	UndirectedGraphNode* res = s.cloneGraph(start);
	cout << res -> label << endl << res -> neighbors[0] -> label << endl << res -> neighbors[1] -> label << endl;
	return 0;
}