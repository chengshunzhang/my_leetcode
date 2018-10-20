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
        RandomListNode* p = head, * result = NULL, * q = NULL, * pre = NULL;
        while(p != NULL) {
            pre = p;
            p = p -> next;
            pre -> next = new RandomListNode(pre -> label);
            pre -> next -> next = p;
        }
        p = head;
        while(p != NULL) {
            if(p -> random != NULL) {
                p -> next -> random = p -> random -> next;
            }
            p = p -> next -> next;
        }
        p = head;
        result = p -> next;
        q = result;
        while(p != NULL) {
            p -> next = q -> next;
            p = p -> next;
            if(q -> next != NULL) {
                q -> next = p -> next;
            }
            q = q -> next;
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