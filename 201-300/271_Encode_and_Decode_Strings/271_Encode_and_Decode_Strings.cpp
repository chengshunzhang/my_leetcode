#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result;
        for(string str : strs) {
            result += to_string(str.size()) + "-" + str;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int pos = 0, n = s.size();
        vector<string> result;
        while(pos < n) {
            int p = pos;
            while(p < n && s[p] != '-') {
                p++;
            }
            int len = stoi(s.substr(pos, p - pos));
            result.push_back(s.substr(p + 1, len));
            pos = p + 1 + len;
        }
        return result;
    }
};

int main() {
    vector<string> strs = {"hello", "world"};
    Codec codec;
    string encoded = codec.encode(strs);
    vector<string> result = codec.decode(encoded);
    for(string str : result) {
        cout << str << endl;
    }
    return 0;
}