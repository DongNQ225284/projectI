#include <bits/stdc++.h>
using namespace std;

vector<int> b;

void print(vector<int> b) {
	for (int i = 0; i < b.size(); i++) {
		cout << b[i];
	}
	cout << endl;
}

void Try(int length, int k = 1) {
	for (int v = 0; v <= 1; v++) {
		if (v == 1 && b[b.size() - 1] == 1) continue;
		b.push_back(v);
		if (k < length) {
			Try(length, k + 1);
		} else {
			print(b);
		}
		b.pop_back();
	}
}

int main() {
	int n;
	cin >> n;
	Try(n);
	return 0;
}
