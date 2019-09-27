// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    char buffer[4];
    int bufferPos = 0;
    int bufferSize = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int result = 0;
        while(result < n) {
            if(bufferPos == bufferSize) {
                bufferSize = read4(buffer);
                bufferPos = 0;
            }
            if(bufferSize == 0) {
                break;
            }
            buf[result++] = buffer[bufferPos++];
        }
        return result;
    }
};