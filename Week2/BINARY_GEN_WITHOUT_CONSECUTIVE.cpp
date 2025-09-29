/*
Problem: Binary sequences generation without consecutive 11

Description:
Given an integer n, write a program that generates all binary sequences without consecutive 11 in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic order, each sequence in a line
Example
Input
3
Output
000
001
010
100
101
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int n;
    vector<int> b;

    void print() {
        for (int v : b) cout << v;
        cout << "\n";
    }

    void Try(int k = 1) {
        for (int v = 0; v <= 1; v++) {
            if (v == 1 && b.back() == 1) continue;
            b.push_back(v);
            if (k < n) {
                Try(k + 1);
            } else {
                print();
            }
            b.pop_back();
        }
    }

    void solve(int n) {
		this->n = n;
        Try(1);
    }
};

int main() {
	int n;
    cin >> n;
    Solution solution;
    solution.solve(n);
    return 0;
}
