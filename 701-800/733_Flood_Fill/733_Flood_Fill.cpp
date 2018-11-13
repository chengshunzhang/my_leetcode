#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void helper(vector<vector<int> >& newImage, int row, int col, int& newColor, int& original) {
        newImage[row][col] = newColor;
        pair<int, int> offset[] = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};
        for(int i = 0; i < 4; i++) {
            int newRow = row + offset[i].first, newCol = col + offset[i].second;
            if(newRow >= 0 && newRow < newImage.size() && newCol >= 0 && newCol < newImage[0].size() && newImage[newRow][newCol] == original) {
                helper(newImage, newRow, newCol, newColor, original);
            }
        }
    }
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        vector<vector<int> > result(image);
        int original = image[sr][sc];
        if(newColor == original) {
            return result;
        }
        helper(result, sr, sc, newColor, original);
        return result;
    }
};

int main() {
	int n[][3] = {{1,1,1},{1,1,0},{1,0,1}};
	vector<vector<int> > image;
	for(int i = 0; i < 3; i++) {
		image.push_back(vector<int> (n[i],n[i]+3));
	}
	Solution s;
	vector<vector<int> > res = s.floodFill(image, 1, 1, 2);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}