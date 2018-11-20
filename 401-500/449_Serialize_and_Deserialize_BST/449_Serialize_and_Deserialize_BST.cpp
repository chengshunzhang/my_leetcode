#include <string>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root) {
	if(root == NULL) {
		return;
	}
	cout << root -> val << ' ';
	preOrder(root -> left);
	preOrder(root -> right);
}

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "#";
        }
        string result = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL) {
                result += "#,";
            } else {
                result += to_string(temp -> val) + ",";
                q.push(temp -> left);
                q.push(temp -> right);
            }
        }
        result.pop_back();
        while(result.back() == '#') {
            result.pop_back();
            result.pop_back();
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") {
            return NULL;
        }
        int start = 0, end = 1;
        string cur = "";
        while(end < data.size() && data[end] != ',') {
            end++;
        }
        cur = data.substr(start, end);
        TreeNode* root = new TreeNode(stoi(cur));
        queue<TreeNode*> q;
        q.push(root);
        while(end < data.size()) {
            TreeNode* temp = q.front();
            q.pop();
            start = end + 1;
            end = start + 1;
            while(end < data.size() && data[end] != ',') {
                end++;
            }
            cur = data.substr(start, end - start);
            if(cur != "#") {
                temp -> left = new TreeNode(stoi(cur));
                q.push(temp -> left);
            }
            if(end >= data.size()) {
                break;
            }
            start = end + 1;
            end = start + 1;
            while(end < data.size() && data[end] != ',') {
                end++;
            }
            cur = data.substr(start, end - start);
            if(cur != "#") {
                temp -> right = new TreeNode(stoi(cur));
                q.push(temp -> right);
            }
        }
        return root;
    }
};

int main() {
	Codec obj;
	TreeNode* root = new TreeNode(2);
	root -> left = new TreeNode(1);
	root -> right = new TreeNode(3);
	preOrder(obj.deserialize(obj.serialize(root)));
	cout << endl;
	return 0;
}