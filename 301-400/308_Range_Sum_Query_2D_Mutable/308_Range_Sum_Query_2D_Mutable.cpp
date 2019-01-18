#include <vector>
#include <iostream>
using namespace std;

struct SegmentTreeNode {
    int start, end, middle, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int s, int e, int m, int sm): start(s), end(e), middle(m), sum(sm),
                                                    left(NULL), right(NULL) {}
};

class NumMatrix {
private:
    vector<SegmentTreeNode*> roots;
    vector<vector<int>> nums;
    
    void construct(SegmentTreeNode*& root, vector<int>& sums, int s, int e) {
        int mid = s + (e - s) / 2;
        root = new SegmentTreeNode(s, e, mid, sums[e + 1] - sums[s]);
        if(s == e) {
            return;
        }
        construct(root -> left, sums, s, mid);
        construct(root -> right, sums, mid + 1, e);
    }
    
    void updateHelper(SegmentTreeNode* root, int row, int col, int val) {
        if(root == NULL) {
            return;
        }
        root -> sum = root -> sum - nums[row][col] + val;
        if(col <= root -> middle) {
            updateHelper(root -> left, row, col, val);
        } else {
            updateHelper(root -> right, row, col, val);
        }
    }
    
    int sumHelper(SegmentTreeNode*& root, int s, int e) {
        if(root == NULL) {
            return 0;
        }
        if(s == root -> start && e == root -> end) {
            return root -> sum;
        } else if(e <= root -> middle) {
            return sumHelper(root -> left, s, e);
        } else if(s > root -> middle) {
            return sumHelper(root -> right, s, e);
        } else {
            return sumHelper(root -> left, s, root -> middle) +
                    sumHelper(root -> right, root -> middle + 1, e);
        }
    }
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(!matrix.empty() && !matrix[0].empty()) {
            roots.resize(matrix.size());
            nums.resize(matrix.size());
            for(int i = 0; i < matrix.size(); i++) {
                nums[i].assign(matrix[i].begin(), matrix[i].end());
                vector<int> sums(matrix[i].size() + 1, 0);
                for(int j = 0; j < matrix[i].size(); j++) {
                    sums[j + 1] = sums[j] + matrix[i][j];
                }
                construct(roots[i], sums, 0, matrix[i].size() - 1);
            }
        }
    }
    
    void update(int row, int col, int val) {
        updateHelper(roots[row], row, col, val);
        nums[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int row = row1; row <= row2; row++) {
            sum += sumHelper(roots[row], col1, col2);
        }
        return sum;
    }
};

int main() {
	vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
									{5, 6, 3, 2, 1},
									{1, 2, 0, 1, 5},
									{4, 1, 0, 1, 7},
									{1, 0, 3, 0, 5}};
	NumMatrix numMatrix(matrix);
	cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
	numMatrix.update(3, 2, 2);
	cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
	return 0;
}