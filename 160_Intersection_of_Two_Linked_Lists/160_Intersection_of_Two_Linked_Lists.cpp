#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }
        int na = 0, nb = 0;
        ListNode* pa = headA, * pb = headB;
        while(pa != NULL) {
            pa = pa -> next;
            na++;
        }
        while(pb != NULL) {
            pb = pb -> next;
            nb++;
        }
        pa = headA, pb = headB;
        if(nb > na) {
            int n = nb - na;
            for(int i = 0; i < n; i++) {
                pb = pb -> next;
            }
        } else {
            int n = na - nb;
            for(int i = 0; i < n; i++) {
                pa = pa -> next;
            }
        }
        while(pa != NULL && pb != NULL) {
            if(pa == pb) {
                return pa;
            } else {
                pa = pa -> next;
                pb = pb -> next;
            }
        }
        return NULL;
    }
};

int main() {
    ListNode* headA = new ListNode(1);
    ListNode* headB = headA;
    Solution s;
    cout << s.getIntersectionNode(headA, headB) -> val << endl;
    return 0;
}