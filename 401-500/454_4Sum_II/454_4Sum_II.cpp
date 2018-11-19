#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int result = 0;
        unordered_map<int, int> hash;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                hash[A[i] + B[j]]++;
            }
        }
        for(int i = 0; i < C.size(); i++) {
            for(int j = 0; j < D.size(); j++) {
                int target = -(C[i] + D[j]);
                if(hash.count(target)) {
                    result += hash[target];
                }
            }
        }
        return result;
    }
};

int main() {
	int a[] = {1,2}, b[] = {-2,-1}, c[] = {-1,2}, d[] = {0,2};
	vector<int> A(a,a+2), B(b,b+2), C(c,c+2), D(d,d+2);
	Solution s;
	cout << s.fourSumCount(A, B, C, D) << endl;
	return 0;
}