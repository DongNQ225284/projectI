/*
Problem: Binary sequence generation

Description:
Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic ordder, eac sequence in a line

Example
Input
3
Output
000
001
010
011
100
101
110
111
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int n;
	vector<int> b;

	void print(vector<int> arr) {
        for (int v : arr) cout << v;
        cout << "\n";
    }

	void Try(int k = 1) {
		for (int v = 0; v <= 1; v++) {
			b.push_back(v);
			if (k < n) {
				Try(k + 1);
			} else {
				print(b);
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
