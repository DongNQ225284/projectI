/*
Problem: Compute C_k_n

Description:
Given two positive integers k and n. Compute C(k,n) which is the number of ways to select k objects from a given set of n objects.
Input
Line 1: two positive integers k and n (1 <= k,n <= 999)
Output
Write te value C(k,n) modulo 1e9+7

Example
Input
3  5
Output
10
*/
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution {
public:
	int a[1000][1000];

	int C(int k, int n) {
		if (k > n) return -1;
		if (a[k][n] != 0) return a[k][n];
		
		if (k == n || k == 0) {
			a[k][n] = 1;
			return 1;
		}
		
		a[k][n] = C(k, n-1) + C(k-1, n-1); //C(k, n) = C(k, n-1) + C(k-1, n-1)
		
		a[k][n] %= MOD;
		
		return a[k][n];
	}

	void solve(int k, int n) {
		cout << C(k, n) << endl;
	}
};

int main() {
	int k, n;
	cin >> k >> n;
	Solution solution;
	solution.solve(k, n);
	return 0;
}
