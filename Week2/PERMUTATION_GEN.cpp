/*
Problem: Permutation generation

Description:
Given an integer n, write a program to generate all permutations of 1, 2, ..., n in a lexicalgraphic order (elements of a permutation are separated by a SPACE character).
Example
Input 
3
Output
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
*/
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int n;
    vector<int> a;

    void print(vector<int> arr) {
        for (int v : arr) cout << v << " ";
        cout << endl;
    }

    void solve(int n) {
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        do {
            print(a);
        } while (next_permutation(a.begin(), a.end()));
    }
};

int main() { 
    int n;
    cin >> n;
    Solution solution;
    solution.solve(n);
    return 0;
}
