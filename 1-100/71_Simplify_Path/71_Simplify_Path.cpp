#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string result("/");
        int n = path.size(), last_dir = 0;
        vector<int> dir_pos(1, 0);
        int nDir = 1;
        if(n > 1) {
            int i = 0;
            while(i < n) {
                i++;
                while(i < n && path[i] == '/') {
                    i++;
                }
                if(i < n) {
                    if(path[i] == '.' && (i == n - 1 || path[i + 1] == '/')) {
                        i++;
                    } else if(path[i] == '.' && (i < n - 1 && path[i + 1] == '.') && (i == n - 2 || path[i + 2] == '/')) {
                        i += 2;
                        if(nDir > 1) {
                            result = result.substr(0, last_dir);
                            dir_pos.pop_back();
                            nDir--;
                            last_dir = dir_pos[nDir - 1];
                        }
                    } else {
                        int j = i;
                        while(j < n && path[j] != '/') {
                            j++;
                        }
                        dir_pos.push_back(result.size());
                        nDir++;
                        last_dir = dir_pos[nDir - 1];
                        result.append(path, i, j - i);
                        result.append("/");
                        i = j;
                    }
                }
            }
        }
        if(result.size() > 1) {
            result.pop_back();
        }
        return result;
    }
};

int main() {
	Solution s;
	string str;
	str = s.simplifyPath("/a/b/./../../c/");
	cout << endl << str << endl;
	return 0;
}