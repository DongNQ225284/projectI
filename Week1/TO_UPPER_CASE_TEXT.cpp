/*
Problem: Convert a TEXT to Upper-Case

Description:
Given a TEXT, write a program that converts the TEXT to upper-case. 

Input
The TEXT

Output
The TEXT in which characters are converted into upper-case

Example 
Input 
Hello John,
How are you?

Bye,

Output 
HELLO JOHN,
HOW ARE YOU?

BYE, 
*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void solve() { 
        string line;
        while (getline(cin, line)) {
            for (char &c : line) {
                c = toupper(c);
            }
            cout << line << endl;
        }
    }
};

int main() {
    Solution solution;
    solution.solve();
    return 0;
}
