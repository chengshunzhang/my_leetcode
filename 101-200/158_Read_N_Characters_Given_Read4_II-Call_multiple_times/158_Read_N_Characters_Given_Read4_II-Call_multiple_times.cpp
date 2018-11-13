// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    char buffer[4];
    int bufferPos;
    int number;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    Solution() {
        bufferPos = 0;
        number = 0;
    }
    int read(char *buf, int n) {
        if(n == 0) {
            return 0;
        }
        int result = 0;
        while(result < n) {
            if(bufferPos == 0) {
                number = read4(buffer);
            }
            if(number == 0) {
                return result;
            }
            while(result < n && bufferPos < number) {
                buf[result++] = buffer[bufferPos++];
            }
            if(bufferPos == number) {
                bufferPos = 0;
            }
        }
        return result;
    }
};