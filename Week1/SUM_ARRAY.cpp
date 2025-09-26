/*
Problem: Sum of elements in a sequence

Description:
Given a sequence of integers a1, a2, ..., an. Compute the sum Q of elements of this sequence.
Input
Line 1: contains n (1 <= n <= 1000000)
Line 2: contains a1, a2, ..., an (-10000 <= ai <= 10000)
Output
Write the value of Q
Example
Input
4
3 2 5 4
Output
14
*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void solve(vector<int> arr) { 
        long long sum = accumulate(arr.begin(), arr.end(), 0LL);
        cout << sum << endl;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    Solution solution;
    solution.solve(a);
    return 0;
}
