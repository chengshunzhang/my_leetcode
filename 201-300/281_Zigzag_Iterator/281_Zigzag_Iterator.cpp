#include <vector>
#include <iostream>
using namespace std;

class ZigzagIterator {
private:
    int pos1, pos2;
    vector<int> v1, v2;
    bool first;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        pos1 = 0;
        this -> v1 = v1;
        pos2 = 0;
        this -> v2 = v2;
        if(!v1.empty()) {
            first = true;
        } else {
            first = false;
        }
    }

    int next() {
        if(first) {
            if(pos2 < v2.size()) {
                first = false;
            }
            return v1[pos1++];
        } else {
            if(pos1 < v1.size()) {
                first = true;
            }
            return v2[pos2++];
        }
    }

    bool hasNext() {
        return pos1 < v1.size() || pos2 < v2.size();
    }
};

int main() {
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4, 5, 6};
    ZigzagIterator zigzagIterator(v1, v2);
    while(zigzagIterator.hasNext()) {
        cout << zigzagIterator.next() << ",";
    }
    cout << "\b " << endl;
    return 0;
}