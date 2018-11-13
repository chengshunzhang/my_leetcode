#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(), n2 = b.size(), carry = 0;
        string reverse_a(a), reverse_b(b), result;
        for(int i = 0, j = n1 - 1; i < j; i++, j--) {
            char temp = reverse_a[i];
            reverse_a[i] = reverse_a[j];
            reverse_a[j] = temp;
        }
        for(int i = 0, j = n2 - 1; i < j; i++, j--) {
            char temp = reverse_b[i];
            reverse_b[i] = reverse_b[j];
            reverse_b[j] = temp;
        }
        int idx = 0;
        while(idx < n1 && idx < n2) {
            if(reverse_a[idx] == '0' && reverse_b[idx] == '0') {
                if(carry == 0) {
                    result.append("0");
                } else {
                    result.append("1");
                    carry = 0;
                }
            } else if(reverse_a[idx] == '1' && reverse_b[idx] == '1') {
                carry == 0 ? result.append("0") : result.append("1");
                carry = 1;
            } else {
                if(carry == 0) {
                    result.append("1");
                } else {
                    result.append("0");
                }
            }
            idx++;
        }
        if(n1 == n2) {
            if(carry) {
                result.append("1");
            }
        }
        if(idx < n1) {
            if(carry == 0) {
                result.append(reverse_a.substr(idx));
            } else {
                while(idx < n1 && reverse_a[idx] == '1') {
                    result.append("0");
                    idx++;
                }
                result.append("1");
                if(++idx < n1) {
                    result.append(reverse_a.substr(idx));
                }
            }
        }
        if(idx < n2) {
            if(carry == 0) {
                result.append(reverse_b.substr(idx));
            } else {
                while(idx < n2 && reverse_b[idx] == '1') {
                    result.append("0");
                    idx++;
                }
                result.append("1");
                if(++idx < n2) {
                    result.append(reverse_b.substr(idx));
                }
            }
        }
        for(int i = 0, j = result.size() - 1; i < j; i++, j--) {
            char temp = result[i];
            result[i] = result[j];
            result[j] = temp;
        }
        return result;
    }
};

int main() {
    string s1("11"), s2("1001");
    Solution s;
    cout << s.addBinary(s1, s2) << endl;
    return 0;
}