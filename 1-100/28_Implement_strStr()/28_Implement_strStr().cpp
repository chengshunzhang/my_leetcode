#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if(m == 0)
            return 0;
        if(!n || n < m)
            return -1;
        int last = n - m + 1;
        int i;
        for(i = 0; i < last; i++) {
            int j;
            for(j = 0; j < m; j++)
                if(haystack[i + j] != needle[j])
                    break;
            if(j == m)
                break;
        }
        return i == last ? -1 : i;
    }
};

int main() {
    string s1("hello"), s2("ll");
    Solution s;
    cout << s.strStr(s1, s2) << endl;
    return 0;
}