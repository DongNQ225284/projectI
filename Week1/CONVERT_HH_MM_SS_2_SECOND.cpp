/*
Problem: Convert time string hh:mm:ss to seconds

Description:
Given a time string hh:mm:ss, convert to total seconds.
If the format is incorrect, print "INCORRECT".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string s) {
        //12:23:44
        if (s.size() != 8 || s[2] != ':' || s[5] != ':') {
            cout << "INCORRECT" << endl;
            return;
        }

        int hh, mm, ss;
        try {
            hh = stoi(s.substr(0, 2));
            mm = stoi(s.substr(3, 5));
            ss = stoi(s.substr(6, 8));
        } catch(...) {
            cout << "INCORRECT" << endl;
            return;
        }

        if (hh < 0 || hh > 23 || mm < 0 || mm > 59 || ss < 0 || ss > 59) {
            cout << "INCORRECT" << endl;
            return;
        }

        cout << hh*3600 + mm*60 + ss << endl;
    }
};

int main() {
    string s;
    cin >> s;
    Solution solution = Solution();
    solution.solve(s);
    return 0;
}