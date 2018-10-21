#include <queue>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct comp {
    bool operator() (ListNode* l1, ListNode* l2) {
        return l1 -> val > l2 -> val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, comp> minHeap;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                minHeap.push(lists[i]);
            }
        }
        ListNode* dummy = new ListNode(-1), * p = dummy;
        while(!minHeap.empty()) {
            p -> next = new ListNode(minHeap.top() -> val);
            if(minHeap.top() -> next != NULL) {
                minHeap.push(minHeap.top() -> next);
            }
            minHeap.pop();
            p = p -> next;
        }
        return dummy -> next;
    }
};

int main() {
	Solution s;
	vector<ListNode*> lists;
	ListNode* l = new ListNode(1);
	l -> next = new ListNode(4);
	l -> next -> next = new ListNode(5);
	lists.push_back(l);
	l = new ListNode(1);
	l -> next = new ListNode(3);
	l -> next -> next = new ListNode(4);
	lists.push_back(l);
	l = new ListNode(2);
	l -> next = new ListNode(6);
	lists.push_back(l);
	ListNode* res = s.mergeKLists(lists);
	ListNode* p = res;
	while(p != NULL) {
		cout << p -> val;
		p = p -> next;
	}
	cout << endl;
	return 0;
}