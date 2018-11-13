#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "";
        }
        string result("[");
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL) {
                result.append("null,");
            } else {
                q.push(temp -> left);
                q.push(temp -> right);
                result.append(to_string(temp -> val) + ",");
            }
        }
        result[result.size() - 1] = ']';
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) {
            return NULL;
        }
        TreeNode* root;
        queue<TreeNode*> q;
        int pos = 1;
        for(int i = pos + 1; i < data.size(); i++) {
            if(data[i] == ',' || data[i] == ']') {
                root = new TreeNode(stoi(data.substr(pos, i - pos)));
                q.push(root);
                pos = i + 1;
                break;
            }
        }
        while(pos < data.size()) {
            TreeNode* temp = q.front();
            q.pop();
            if(data[pos] != 'n') {
                for(int i = pos + 1; i < data.size(); i++) {
                    if(data[i] == ',' || data[i] == ']') {
                        temp -> left = new TreeNode(stoi(data.substr(pos, i - pos)));
                        q.push(temp -> left);
                        pos = i + 1;
                        break;
                    }
                }
            } else {
                pos = pos + 5;
            }
            if(data[pos] != 'n') {
                for(int i = pos + 1; i < data.size(); i++) {
                    if(data[i] == ',' || data[i] == ']') {
                        temp -> right = new TreeNode(stoi(data.substr(pos, i - pos)));
                        q.push(temp -> right);
                        pos = i + 1;
                        break;
                    }
                }
            } else {
                pos = pos + 5;
            }
        }
        return root;
    }
};

void preOrder(TreeNode* root) {
	if(root == NULL) {
		return;
	}
	cout << root -> val << ' ';
	preOrder(root -> left);
	preOrder(root -> right);
}

int main() {
	int n[] = {1,2,3,1<<31,1<<31,4,5}, pos = 1;
    TreeNode* root = new TreeNode(n[0]);
    queue<TreeNode*> q;
    q.push(root);
    while(pos < 7) {
    	TreeNode* temp = q.front();
    	q.pop();
    	if(n[pos] != (1<<31)) {
    		temp -> left = new TreeNode(n[pos]);
    		q.push(temp -> left);
    	}
    	pos++;
    	if(n[pos] != (1<<31)) {
    		temp -> right = new TreeNode(n[pos]);
    		q.push(temp -> right);
    	}
    	pos++;
    }
    Codec obj;
    string s = obj.serialize(root);
    cout << s << endl;
    root = obj.deserialize(s);
    preOrder(root);
    cout << endl;
	return 0;
}