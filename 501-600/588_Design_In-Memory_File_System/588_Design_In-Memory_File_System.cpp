#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    unordered_map<string, Node*> directory;
    unordered_map<string, string> file;
};
class FileSystem {
private:
    Node* root;
    string getName(string& path) {
        if(path.empty()) {
            return "";
        }
        int j = 1;
        while(j < path.size() && path[j] != '/') {
            j++;
        }
        string result = path.substr(0, j);
        if(j < path.size()) {
            path = path.substr(j + 1);
        } else {
            path = "";
        }
        return result;
    }
public:
    FileSystem() {
        root = new Node;
    }
    
    vector<string> ls(string path) {
        vector<string> result;
        Node* p = root;
        path = path.substr(1);
        string dir = "";
        while(!path.empty()) {
            dir = getName(path);
            if(!(p -> directory).count(dir)) {
                result.push_back(dir);
                return result;
            }
            p = (p -> directory)[dir];
        }
        for(unordered_map<string, Node*>::iterator it = (p -> directory).begin(); it != (p -> directory).end(); it++) {
            result.push_back(it -> first);
        }
        for(unordered_map<string, string>::iterator it = (p -> file).begin(); it != (p -> file).end(); it++) {
            result.push_back(it -> first);
        }
        sort(result.begin(), result.end());
        return result;
    }
    
    void mkdir(string path) {
        Node* p = root;
        path = path.substr(1);
        string dir = getName(path);
        while((p -> directory).count(dir)) {
            p = (p -> directory)[dir];
            dir = getName(path);
        }
        while(dir != "") {
            (p -> directory)[dir] = new Node;
            p = (p -> directory)[dir];
            dir = getName(path);
        }
    }
    
    void addContentToFile(string filePath, string content) {
        Node* p = root;
        filePath = filePath.substr(1);
        string dir = getName(filePath);
        while(!filePath.empty()) {
            p = (p -> directory)[dir];
            dir = getName(filePath);
        }
        if((p -> file).count(dir)) {
            (p -> file)[dir] += content;
        } else {
            (p -> file)[dir] = content;
        }
    }
    
    string readContentFromFile(string filePath) {
        Node* p = root;
        filePath = filePath.substr(1);
        string dir = getName(filePath);
        while(!filePath.empty()) {
            p = (p -> directory)[dir];
            dir = getName(filePath);
        }
        return (p -> file)[dir];
    }
};

int main() {
	FileSystem fs;
	vector<string> res = fs.ls("/");
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	fs.mkdir("/a/b/c");
	fs.addContentToFile("/a/b/c/d", "hello");
	res = fs.ls("/");
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	cout << fs.readContentFromFile("/a/b/c/d") << endl;
	return 0;
}