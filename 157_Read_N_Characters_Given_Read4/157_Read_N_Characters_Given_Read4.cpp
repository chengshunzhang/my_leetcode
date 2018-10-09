#include <iostream>
using namespace std;

//Forward declaration of the read4 API.
int read4(char *buf) {
    int n = 0;
    for(int i = 0; i < 4 && buf[i] != '\0'; i++) {
        n++;
    }
    return n;
};

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int offset = 4, num = read4(buf), result = num;
        while(result < n && num == 4) {
            num = read4(buf + offset);
            offset += 4;
            result += num;
        }
        if(result >= n) {
            return n;
        } else {
            return result;
        }
    }
};

int main() {
    Solution s;
    char buf[] = "abc";
    int n = 4;
    cout << s.read(buf, n) << endl;
    return 0;
}