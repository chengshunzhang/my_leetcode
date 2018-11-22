class NestedIterator {
private:
    vector<NestedInteger> nList;
    list<int> buffer;
    int pos;
    list<int> helper(vector<NestedInteger>& lt) {
        list<int> result;
        for(int i = 0; i < lt.size(); i++) {
            if(lt[i].isInteger()) {
                result.push_back(lt[i].getInteger());
            } else {
                result.splice(result.end(), helper(lt[i].getList()));
            }
        }
        return result;
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        nList.assign(nestedList.begin(), nestedList.end());
        pos = 0;
    }

    int next() {
        int result = buffer.front();
        buffer.pop_front();
        return result;
    }

    bool hasNext() {
        if(!buffer.empty()) {
            return true;
        }
        if(pos == nList.size()) {
            return false;
        }
        if(nList[pos].isInteger()) {
            buffer.push_back(nList[pos++].getInteger());
            return true;
        } else {
            vector<NestedInteger> temp = nList[pos++].getList();
            buffer = helper(temp);
            return hasNext();
        }
    }
};