/*
Problem: Extract Year, Month, Date from a String YYYY-MM-DD

Description:
Given a date which is a string under the format YYYY-MM-DD (in which YYYY is the year, MM is the month (the month í from 1 to 12), and DD is the date (the date is from 1 to 31)). Extract the year, month and date.
Input
Line 1: contains a string s  
Output
if s is not under the format YYYY-MM-DD, then write INCORRECT. Otherwise, write year, month, and date separated by a SPACE character

Example
Input
2023-10-04
Output
2023 10 4

Input
2023-10-4
Output
INCORRECT 

Input
2023-10 04
Output
INCORRECT
*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void solve(string s) { 
        if (s.size() != 10 || s[4] != '-' || s[7] != '-') {
            cout << "INCORRECT" << endl;
            return;
        }

        int yy, mm, dd;
        try {
            yy = stoi(s.substr(0,4));
            mm = stoi(s.substr(5,2));
            dd = stoi(s.substr(8,2));
        } catch(...) {
            cout << "INCORRECT" << endl;
            return;
        }

        if (mm < 1 || mm > 12) {
            cout << "INCORRECT" << endl;
            return;
        }

        int day_in_february;
        if (yy % 400 == 0)      day_in_february = 29;
        else if (yy % 100 == 0) day_in_february = 28;
        else if (yy % 4 == 0)   day_in_february = 29;
        else day_in_february = 28;

        vector<int> day_in_months = {31, day_in_february, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int num_day = day_in_months[mm - 1];
        if (dd < 1 || dd > num_day) {
            cout << "INCORRECT" << endl;
            return;
        }
        cout << yy << " " << mm << " " << dd << endl;
    }
};

int main() {
    string s;
    cin >> s;
    Solution solution = Solution();
    solution.solve(s);
    return 0;
}
