/*
Problem: Add Subtract Multiplication Division of A and B

Description:
Given 2 integers a and b. Compute a+b, a-b, a*b, a/b.
*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void solve(int a, int b) {
        cout << a + b << " " << a - b << " " << a * b << " " << a / b << endl;
    }
};

int main() {
    int a, b;
    cin >> a >> b;
    Solution solution = Solution();
    solution.solve(a, b);
    return 0;
}
