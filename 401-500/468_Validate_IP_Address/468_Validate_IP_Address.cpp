#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    string checkIPv4(string IP) {
        int start = 0, count = 0;
        IP.push_back('.');
        for(int i = 0; i < IP.size(); i++) {
            if(count == 4) {
                return "Neither";
            }
            if(IP[i] == '.') {
                count++;
                string cur = IP.substr(start, i - start);
                if(cur.empty() || cur.size() > 3) {
                    return "Neither";
                }
                for(int j = 0; j < cur.size(); j++) {
                    if(cur[j] < '0' || cur[j] > '9') {
                        return "Neither";
                    }
                }
                int value = stoi(cur);
                if(!(value > 0 && value < 256 && cur[0] != '0') && 
                   !(value == 0 && cur.size() == 1)) {
                    return "Neither";
                }
                start = i + 1;
            }
        }
        if(count < 4) {
            return "Neither";
        }
        return "IPv4";
    }
    
    string checkIPv6(string IP) {
        int start = 0, count = 0;
        IP.push_back(':');
        for(int i = 0; i < IP.size(); i++) {
            if(count == 8) {
                return "Neither";
            }
            if(IP[i] == ':') {
                count++;
                string cur = IP.substr(start, i - start);
                if(cur.empty() || cur.size() > 4) {
                    return "Neither";
                }
                for(int j = 0; j < cur.size(); j++) {
                    if(!(cur[j] >= '0' && cur[j] <= '9') 
                      && !(cur[j] >= 'a' && cur[j] <= 'f')
                      && !(cur[j] >= 'A' && cur[j] <= 'F')) {
                        return "Neither";
                    }
                }
                start = i + 1;
            }
        }
        if(count < 8) {
            return "Neither";
        }
        return "IPv6";
    }
public:
    string validIPAddress(string IP) {
        for(int i = 0; i < 5; i++) {
            if(IP[i] == '.') {
                return checkIPv4(IP);
            } else if(IP[i] == ':') {
                return checkIPv6(IP);
            }
        }
        return "Neither";
    }
};

int main() {
    Solution s;
    cout << s.validIPAddress("172.16.254.1") << endl;
    return 0;
}