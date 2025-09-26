/*
Problem: k-Subsequence even

Description:
Given a sequence of integers a1, a2, . . ., an. A k-subsequence is define to be a sequence of k consecutive elements: ai, ai+1, . . ., ai+k-1. The weight of a k-subsequence is the sum of its elements.
Given positive integers k and m. Compute the number Q of k-subsequences such that the weight is even.
Input
Line 1: contains 2 positive integers n, k (1 <= n <= 100000, 1 <= k <= n/2)
Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)
Output
Write the value Q
Example
Input
6  3
2 4 5 1 1 2 
Output
2

0 2 6 11 12 13 15
*/


#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void solve(vector<int> arr, int k) { 
        int n = arr.size();

        vector<long long> prefix_sum(n + 1);
        prefix_sum[0] = 0;
        for (int i = 0; i < n; i++) prefix_sum[i + 1] = prefix_sum[i] + arr[i];
        
        int count = 0;

        for (int i = 1; i < n - k + 2; i++) {
            long long weight = prefix_sum[i + k - 1] - prefix_sum[i - 1];
            if (!(weight & 1)) count++;
        } 

        cout << count << endl;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    Solution solution;
    solution.solve(a, k);
    return 0;
}
