#include <vector>
#include <iostream>
using namespace std;

class Vector2D {
private:
    vector<vector<int>>::iterator rowIt;
    vector<vector<int>>::iterator endIt;
    vector<int>::iterator colIt;
public:
    Vector2D(vector<vector<int>>& v) {
        rowIt = v.begin();
        endIt = v.end();
        while(rowIt != endIt && (*rowIt).begin() == (*rowIt).end()) {
            rowIt++;
        }
        if(rowIt != endIt) {
            colIt = (*rowIt).begin();
        }
    }
    
    int next() {
        int result = *colIt;
        colIt++;
        if(colIt == (*rowIt).end()) {
            rowIt++;
            while(rowIt != endIt && (*rowIt).begin() == (*rowIt).end()) {
                rowIt++;
            }
            if(rowIt != endIt) {
                colIt = (*rowIt).begin();
            }
        }
        return result;
    }
    
    bool hasNext() {
        return rowIt != endIt;
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