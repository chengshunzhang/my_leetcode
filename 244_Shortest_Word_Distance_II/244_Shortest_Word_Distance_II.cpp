#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class WordDistance {
private:
    unordered_map<string, vector<int> > myMap;
public:
    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); i++) {
            myMap[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int result = ((uint)1 << 31) - 1;
        vector<int> positions1 = myMap[word1];
        vector<int> positions2 = myMap[word2];
        for(int i = 0; i < positions1.size(); i++) {
            for(int j = 0; j < positions2.size(); j++) {
                int distance = abs(positions1[i] - positions2[j]);
                if(distance < result) {
                    result = distance;
                }
            }
        }
        return result;
    }
};

int main() {
	vector<string> words;
	words.push_back("practice");words.push_back("makes");words.push_back("perfect");words.push_back("coding");
	words.push_back("makes");
	WordDistance wd(words);
	cout << wd.shortest("practice", "perfect") << endl;
	cout << wd.shortest("makes", "perfect") << endl;
	return 0;
}