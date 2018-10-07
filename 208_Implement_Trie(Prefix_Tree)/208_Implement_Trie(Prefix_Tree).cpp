#include <string>
#include <iostream>
using namespace std;

struct TrieNode {
    bool have;
    TrieNode* pointers[26];
    TrieNode() : have(false) {
        for(int i = 0; i < 26; i++) {
            pointers[i] = NULL;
        }
    }
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++) {
            int id = word[i] - 'a';
            if(p -> pointers[id] == NULL) {
                p -> pointers[id] = new TrieNode;
            }
            p = p -> pointers[id];
        }
        p -> have = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++) {
            int id = word[i] - 'a';
            if(p -> pointers[id] == NULL) {
                return false;
            }
            p = p -> pointers[id];
        }
        return p -> have;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i = 0; i < prefix.size(); i++) {
            int id = prefix[i] - 'a';
            if(p -> pointers[id] == NULL) {
                return false;
            }
            p = p -> pointers[id];
        }
        return true;
    }
};

int main() {
	Trie trie;
	trie.insert("apple");
	cout << trie.search("apple") << endl;   // returns true
	cout << trie.search("app") << endl;     // returns false
	cout << trie.startsWith("app") << endl; // returns true
	trie.insert("app");   
	cout << trie.search("app") << endl;     // returns true
	return 0;
}