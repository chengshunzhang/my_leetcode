#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

bool myComp(pair<int, string>& p1, pair<int, string>& p2) {
    return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
}

class AutocompleteSystem {
private:
    string curInput;
    unordered_map<string, int> storage;
    list<pair<int, string> > processing;
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        curInput = "";
        for(int i = 0; i < sentences.size(); i++) {
            storage[sentences[i]] = times[i];
        }
    }
    
    vector<string> input(char c) {
        if(c == '#') {
            storage[curInput]++;
            curInput = "";
            processing.clear();
            return vector<string> ();
        }
        vector<string> result;
        curInput += c;
        int len = curInput.size();
        if(len == 1) {
            for(unordered_map<string, int>::iterator it = storage.begin(); it != storage.end(); it++) {
                if((it -> first)[0] == c) {
                    processing.push_back(make_pair(it -> second, it -> first));
                }
            }
            processing.sort(myComp);
            list<pair<int, string> >::iterator itr = processing.begin();
            while(itr != processing.end() && result.size() < 3) {
                result.push_back((*itr).second);
                itr++;
            }
        } else if(!processing.empty()){
            list<pair<int, string> >::iterator itr = processing.begin();
            while(itr != processing.end() && result.size() < 3) {
                if((*itr).second.substr(0, len) == curInput) {
                    result.push_back((*itr).second);
                    itr++;
                } else {
                    processing.erase(itr++);
                }
            }
        }
        return result;
    }
};

int main() {
	string s[] = {"i love you", "island", "ironman", "i love leetcode"};
	int t[] = {5,3,2,2};
	vector<string> sentences(s, s+4);
	vector<int> times(t,t+4);
	AutocompleteSystem obj(sentences, times);
	vector<string> res = obj.input('i');
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ',';
	}
	cout << endl;
	res = obj.input(' ');
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ',';
	}
	cout << endl;
	res = obj.input('a');
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ',';
	}
	cout << endl;
	res = obj.input('#');
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ',';
	}
	cout << endl;
	return 0;
}