#include <vector>
#include <iostream>
using namespace std;

class Vector2D {
private:
    int row;
    int col;
    vector<vector<int>> the2DVector;
public:
    Vector2D(vector<vector<int>>& v) {
        row = col = 0;
        the2DVector.assign(v.begin(), v.end());
        while(row < the2DVector.size() && the2DVector[row].empty()) {
            row++;
        }
    }
    
    int next() {
        int i = row, j = col;
        if(col + 1 == the2DVector[row].size()) {
            row++;
            while(row < the2DVector.size() && the2DVector[row].empty()) {
                row++;
            }
            col = 0;
        } else {
            col++;
        }
        return the2DVector[i][j];
    }
    
    bool hasNext() {
        return row < the2DVector.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    vector<vector<int>> v;
    vector<int> temp;
    v.push_back(temp);
    Vector2D vector2D(v);
    cout << vector2D.hasNext() << endl;
    return 0;
}