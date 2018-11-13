#include <string>
#include <iostream>
using namespace std;

struct TrieNode {
    bool haveWord;
    TrieNode* child[26];
    TrieNode() : haveWord(false) {
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;
    bool searchHelper(TrieNode* root, string word, int pos) {
        if(root == NULL) {
            return false;
        }
        if(pos == word.size()) {
            return root -> haveWord;
        }
        if(word[pos] == '.') {
            for(int i = 0; i < 26; i++) {
                if(searchHelper(root -> child[i], word, pos + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            return searchHelper(root -> child[word[pos] - 'a'], word, pos + 1);
        }
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++) {
            int id = word[i] - 'a';
            if(p -> child[id] == NULL) {
                p -> child[id] = new TrieNode;
            }
            p = p -> child[id];
        }
        p -> haveWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(root, word, 0);
    }
};

int main() {
	WordDictionary wd;
	wd.addWord("bad");
	wd.addWord("dad");
	wd.addWord("mad");
	cout << wd.search("pad") << endl;// -> false
	cout << wd.search("bad") << endl;// -> true
	cout << wd.search(".ad") << endl;// -> true
	cout << wd.search("b..") << endl;// -> true
	return 0;
}