#include <vector>
#include <iostream>
using namespace std;

struct SegmentTreeNode {
    int start, end, middle, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int s, int e, int m, int sm) : start(s), end(e), middle(m), sum(sm), 
    											left(NULL), right(NULL) {}
};

class NumArray {
private:
    SegmentTreeNode* root;
    vector<int> nums;
    
    void construct(SegmentTreeNode*& root, vector<int>& sums, int s, int e) {
        int mid = s + (e - s) / 2;
        root = new SegmentTreeNode(s, e, mid, sums[e + 1] - sums[s]);
        if(s == e) {
            return;
        }
        construct(root -> left, sums, s, mid);
        construct(root -> right, sums, mid + 1, e);
    }
    
    void updateHelper(SegmentTreeNode* root, int i, int val) {
        if(root == NULL) {
            return;
        }
        root -> sum = root -> sum - nums[i] + val;
        if(i <= root -> middle) {
            updateHelper(root -> left, i, val);
        } else {
            updateHelper(root -> right, i, val);
        }
    }
    
    void sumRangeHelper(SegmentTreeNode* root, int& sum, int i, int j) {
        if(root -> start == i && root -> end == j) {
            sum += root -> sum;
        } else if(j <= root -> middle) {
            sumRangeHelper(root -> left, sum, i, j);
        } else if(i > root -> middle) {
            sumRangeHelper(root -> right, sum, i, j);
        } else {
            sumRangeHelper(root -> left, sum, i, root -> middle);
            sumRangeHelper(root -> right, sum, root -> middle + 1, j);
        }
    }
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        if(!n) {
            root = NULL;
        } else {
            this -> nums.assign(nums.begin(), nums.end());
            vector<int> sums(n + 1, 0);
            int sum = 0;
            for(int i = 0; i < n; i++) {
                sum += nums[i];
                sums[i + 1] = sum;
            }
            construct(root, sums, 0, n - 1);
        }
    }
    
    void update(int i, int val) {
        updateHelper(root, i, val);
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        sumRangeHelper(root, sum, i, j);
        return sum;
    }
};

int main() {
	vector<int> nums = {1, 3, 5};
	NumArray numArray(nums);
	cout << numArray.sumRange(0, 2) << endl;
	numArray.update(1, 2);
	cout << numArray.sumRange(0, 2) << endl;
	return 0;
}