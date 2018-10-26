#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        string strs[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> dic(strs, strs + 28);
        string result = "";
        int group = 1;
        while(num > 0) {
            string temp = "";
            int cur = num % 1000;
            if(cur > 99) {
                temp = dic[cur / 100] + " Hundred ";
                cur = cur % 100;
            }
            if(cur > 0 && cur <= 20) {
                temp += dic[cur];
            } else if(cur > 20) {
                if(cur % 10 == 0) {
                    temp += dic[cur / 10 - 2 + 20];
                } else {
                    temp += dic[cur / 10 - 2 + 20] + " " + dic[cur % 10];
                }
            }
            if(temp != "" && temp.back() == ' ') {
                temp.pop_back();
            }
            if(group == 2 && temp != "") {
                temp += " Thousand ";
            }
            if(group == 3 && temp != "") {
                temp += " Million ";
            }
            if(group == 4) {
                temp += " Billion ";
            }
            result = temp + result;
            num /= 1000;
            group++;
        }
        if(result != "" && result.back() == ' ') {
            result.pop_back();
        }
        return result == "" ? "Zero" : result;
    }
};

int main() {
	int num = 1000;
	Solution s;
	cout << s.numberToWords(num) << endl;
	return 0;
}