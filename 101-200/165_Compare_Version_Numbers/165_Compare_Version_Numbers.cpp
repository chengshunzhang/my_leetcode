#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        if(version1 == version2) {
            return 0;
        }
        while(!version1.empty() && !version2.empty()) {
            int temp1 = -1, temp2 = -1;
            for(int i = 0; i < version1.size(); i++) {
                if(version1[i] == '.') {
                    temp1 = atoi(version1.substr(0, i).c_str());
                    version1 = version1.substr(i + 1);
                    break;
                }
            }
            if(temp1 == -1) {
                temp1 = atoi(version1.c_str());
                version1 = "";
            }
            for(int i = 0; i < version2.size(); i++) {
                if(version2[i] == '.') {
                    temp2 = atoi(version2.substr(0, i).c_str());
                    version2 = version2.substr(i + 1);
                    break;
                }
            }
            if(temp2 == -1) {
                temp2 = atoi(version2.c_str());
                version2 = "";
            }
            if(temp1 < temp2) {
                return -1;
            } else if(temp1 > temp2) {
                return 1;
            }
        }
        if(version1.empty() && version2.empty()) {
            return 0;
        }
        if(version1.empty()) {
            while(!version2.empty()) {
                int temp = -1;
                for(int i = 0; i < version2.size(); i++) {
                    if(version2[i] == '.') {
                        temp = atoi(version2.substr(0, i).c_str());
                        if(temp != 0) {
                            return -1;
                        }
                        version2 = version2.substr(i + 1);
                        break;
                    }
                }
                if(temp == -1) {
                    temp = atoi(version2.c_str());
                    version2 = "";
                    if(temp != 0) {
                        return -1;
                    }
                }
            }
            return 0;
        }
        if(version2.empty()) {
            while(!version1.empty()) {
                int temp = -1;
                for(int i = 0; i < version1.size(); i++) {
                    if(version1[i] == '.') {
                        temp = atoi(version1.substr(0, i).c_str());
                        if(temp != 0) {
                            return 1;
                        }
                        version1 = version1.substr(i + 1);
                        break;
                    }
                }
                if(temp == -1) {
                    temp = atoi(version1.c_str());
                    version1 = "";
                    if(temp != 0) {
                        return 1;
                    }
                }
            }
            return 0;
        }
    }
};

int main() {
	string temp1 = "0.1", temp2 = "1.1";
	Solution s;
	cout << s.compareVersion(temp1, temp2) << endl;
	return 0;
}