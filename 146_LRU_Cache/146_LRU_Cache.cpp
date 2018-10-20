#include <unordered_map>
#include <iostream>
using namespace std;

struct doubleListNode {
    int val, k;
    doubleListNode* left, * right;
    doubleListNode(int v, int x) : val(v), k(x), left(NULL), right(NULL) {}
};

class LRUCache {
private:
    unordered_map<int, doubleListNode*> m;
    int size, max_size;
    doubleListNode* head, * tail;
public:
    LRUCache(int capacity) {
        max_size = capacity;
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if(m.count(key)) {
            if(m[key] != head) {
                if(m[key] == tail) {
                    m[key] -> left -> right = NULL;
                    tail = m[key] -> left;
                } else{
                    m[key] -> left -> right = m[key] -> right;
                    m[key] -> right -> left = m[key] -> left;
                }
                m[key] -> left = NULL;
                m[key] -> right = head;
                head -> left = m[key];
                head = m[key];
            }
            return m[key] -> val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(size == 0) {
            head = new doubleListNode(value, key);
            tail = head;
            size++;
        } else if(max_size == 1) {
            if(m.count(key)) {
                head -> val = value;
            } else {
                m.erase(m.find(head -> k));
                delete head;
                head = new doubleListNode(value, key);
            }
        } else {
            if(m.count(key)) {
                if(m[key] != head) {
                    if(m[key] == tail) {
                        m[key] -> left -> right = NULL;
                        tail = m[key] -> left;
                    } else {
                        m[key] -> left -> right = m[key] -> right;
                        m[key] -> right -> left = m[key] -> left;
                    }
                    m[key] -> left = NULL;
                    m[key] -> right = head;
                    head -> left = m[key];
                    head = m[key];
                }
                m[key] -> val = value;
            } else if(size < max_size) {
                doubleListNode* p = new doubleListNode(value, key);
                p -> right = head;
                head -> left = p;
                head = p;
                size++;
            } else {
                doubleListNode* p = tail;
                tail = tail -> left;
                tail -> right = NULL;
                m.erase(m.find(p -> k));
                delete p;
                p = new doubleListNode(value, key);
                p -> right = head;
                head -> left = p;
                head = p;
            }
        }
        m[key] = head;
    }
};

int main() {
	LRUCache obj(2);
	obj.put(1, 1);
	obj.put(2, 2);
	cout << obj.get(1) << endl;
	obj.put(3, 3);
	cout << obj.get(2) << endl;
	obj.put(4, 4);
	cout << obj.get(1) << endl;
	cout << obj.get(3) << endl;
	cout << obj.get(4) << endl;
	return 0;
}