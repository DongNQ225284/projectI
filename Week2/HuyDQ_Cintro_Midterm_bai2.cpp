/*
Problem: Fibonacci sequence

Description:
Given a fibonacci sequence a[0], a[1], a[2], ... in which:  a[0] = 0, a[1] = 1, a[n] = a[n-1] + a[n-2], for all n >= 2
Given  positive integer n, compute a[n-1].
Input
Line 1: contains a positive integer n (2 <= n <= 21)
Output
Write a[n-1]
Example
Input
9
Output
21
*/
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> a = {0, 1};

    int F(int n) {
        for (int i = 2; i < n; i++) {
            a.push_back(a[i-2] + a[i-1]);
        }
        return a[n-1];
    }

    void solve(int n) {
        cout << F(n) << endl;
    }

};
int main() { 
    int n;
    cin >> n;
    Solution solution;
    solution.solve(n);
    return 0;
}
