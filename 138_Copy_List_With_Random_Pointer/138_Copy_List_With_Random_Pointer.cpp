#include <unordered_map>
#include <iostream>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode* next, * random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) {
            return NULL;
        }
        unordered_map<int, RandomListNode*> m;
        RandomListNode* p = head -> next, * result = new RandomListNode(head -> label), * q = result;
        m[q -> label] = q;
        if(head -> random == NULL) {
            q -> random = NULL;
        } else {
            if(head -> random == head) {
                q -> random = q;
            } else {
                q -> random = new RandomListNode(head -> random -> label);
                m[q -> random -> label] = q -> random;
            }
        }
        while(p != NULL) {
            if(m.count(p -> label)) {
                q -> next = m[p -> label];
                q = q -> next;
            } else {
                q -> next = new RandomListNode(p -> label);
                q = q -> next;
                m[q -> label] = q;
            }
            if(p -> random == NULL) {
                q -> random = NULL;
            } else if(m.count(p -> random -> label)) {
                q -> random = m[p -> random -> label];
            } else {
                q -> random = new RandomListNode(p -> random -> label);
                m[q -> random -> label] = q -> random;
            }
            p = p -> next;
        }
        return result;
    }
};

int main() {
	RandomListNode* head = new RandomListNode(-1);
	Solution s;
	RandomListNode* res = s.copyRandomList(head);
	cout << res -> label << endl;
	return 0;
}