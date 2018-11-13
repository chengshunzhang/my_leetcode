// class Solution {
// public:
//     /**
//      * @param buf Destination buffer
//      * @param n   Maximum number of characters to read
//      * @return    The number of characters read
//      */
//     int read(char *buf, int n) {
//         int offset = 4, num = read4(buf), result = num;
//         while(result < n && num == 4) {
//             num = read4(buf + offset);
//             offset += 4;
//             result += num;
//         }
//         if(result >= n) {
//             return n;
//         } else {
//             return result;
//         }
//     }
// };

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char temp[4];
        int i = 0, num = read4(temp), result = num;
        while(result < n && num == 4) {
            for(int j = 0; j < 4; j++) {
                buf[i++] = temp[j];
            }
            num = read4(temp);
            result += num;
        }
        if(result >= n) {
            for(int j = 0; j < n - result + num; j++) {
                buf[i++] = temp[j];
            }
            return n;
        } else {
            for(int j = 0; j < num; j++) {
                buf[i++] = temp[j];
            }
            return result;
        }
    }
};