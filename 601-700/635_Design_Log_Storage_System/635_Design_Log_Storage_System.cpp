#include <vector>
#include <iostream>
using namespace std;

class LogSystem {
private:
    vector<vector<pair<string, int> > > storage;
public:
    LogSystem() {
        storage.resize(6);
    }
    
    void put(int id, string timestamp) {
        int len = 4;
        string year = timestamp.substr(0, len);
        storage[0].push_back(make_pair(year, id));
        for(int i = 1; i < 6; i++) {
            len += 3;
            string temp = timestamp.substr(0, len);
            storage[i].push_back(make_pair(temp, id));
        }
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int> result;
        int idx, len;
        if(gra == "Year") {
            idx = 0;
            len = 4;
        } else if(gra == "Month") {
            idx = 1;
            len = 7;
        } else if(gra == "Day") {
            idx = 2;
            len = 10;
        } else if(gra == "Hour") {
            idx = 3;
            len = 13;
        } else if(gra == "Minute") {
            idx = 4;
            len = 16;
        } else {
            idx = 5;
            len = 19;
        }
        s = s.substr(0, len);
        e = e.substr(0, len);
        for(int i = 0; i < storage[idx].size(); i++) {
            if(storage[idx][i].first >= s && storage[idx][i].first <= e) {
                result.push_back(storage[idx][i].second);
            }
        }
        return result;
    }
};

int main() {
	LogSystem ls;
	ls.put(1, "2017:01:01:23:59:59");
	ls.put(2, "2017:01:01:22:59:59");
	ls.put(3, "2016:01:01:00:00:00");
	vector<int> res = ls.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year");
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	res = ls.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour");
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}