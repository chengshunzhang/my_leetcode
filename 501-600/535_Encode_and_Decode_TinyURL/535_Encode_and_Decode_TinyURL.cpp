#include <iostream>
#include <string>
#include <unordered_map>
#include <stdlib.h>
using namespace std;

class Solution {
    private:
    unordered_map<string, string> shortToLong;
    unordered_map<string, string> longToShort;
    string str;
public:
    Solution() {
        str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(longToShort.count(longUrl)) {
            return "http://tinyurl.com/" + longToShort[longUrl];
        }
        string shortUrl = "";
        for(int i = 0; i < 6; i++) {
            shortUrl += str[rand() % 62];
        }
        shortToLong[shortUrl] = longUrl;
        longToShort[longUrl] = shortUrl;
        return "http://tinyurl.com/" + shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortToLong[shortUrl.substr(19)];
    }
};

int main() {
	Solution s;
	cout << s.encode("https://leetcode.com/problems/design-tinyurl") << endl;
	cout << s.decode("http://tinyurl.com/fzxc0W") << endl;
	return 0;
}