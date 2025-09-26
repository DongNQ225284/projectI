/*
Problem: Count odd and even elements in array

Description:
Given a sequence of integers a1, a2, ..., an.
Count the number of odd elements and even elements.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int> arr) {
        int odd_count = 0, even_count = 0;
        for (int x : arr) {
            if (x & 1) odd_count++;
            else even_count++;
        }
        cout << odd_count << " " << even_count << endl;
    }
};

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    Solution solution = Solution();
    solution.solve(a);
    return 0;
}