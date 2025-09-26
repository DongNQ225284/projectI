#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

//C(k, n) = C(k, n - 1) + C(k - 1, n - 1)

int C(int k, int n) {
	if (k > n) return -1;
	if (a[k][n] != 0) return a[k][n];
	
	if (k == n || k == 0) {
		a[k][n] = 1;
		return 1;
	}
	
	a[k][n] = C(k, n - 1) + C(k - 1, n - 1);
	a[k][n] %= 1000000007;
	
	return a[k][n];
	
}
int main() {
	int k, n;
	cin >> k >> n;
	cout << C(k, n) << endl;
	return 0;
}
