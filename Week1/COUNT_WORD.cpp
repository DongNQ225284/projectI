/*
Problem: Count number of words in a text

Description:
Given a text, count the number of words.
Ignore spaces, tabs, and line breaks.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve() {
        string line, text;
        while(getline(cin, line)) {
            text += line + " ";
        }
        stringstream ss(text);
        string word;
        int count = 0;
        while (ss >> word) {
            count++;
        }
        cout << count;
    }
};

int main() {
    Solution solution = Solution();
    solution.solve();
    return 0;
}