class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty()) {
            q.push(make_pair(v1.begin(), v1.end()));
        }
        if(!v2.empty()) {
            q.push(make_pair(v2.begin(), v2.end()));
        }
    }

    int next() {
        auto it1 = q.front().first, it2 = q.front().second;
        q.pop();
        int result = *it1;
        auto it = ++it1;
        if(it != it2) {
            q.push(make_pair(it, it2));
        }
        return result;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */