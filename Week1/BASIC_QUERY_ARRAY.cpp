/*
Problem: Basic queries on array

Description:
Given a sequence of integers a1, a2, ..., an. Perform queries:
find-max, find-min, sum, find-max-segment i j.
*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void solve(vector<int> arr) { 
        string query;
        while (true) {
            getline(cin, query);
            stringstream ss(query);
            string command;
            int i, j;
            ss >> command >> i >> j;
            if (command == "***") break;
            if (command == "find-max") {
                cout << *max_element(arr.begin(), arr.end()) << endl;
            } else if (command == "find-min") {
                cout << *min_element(arr.begin(), arr.end()) << endl;
            } else if (command == "sum") {
                long long s = accumulate(arr.begin(), arr.end(), 0LL);
                cout << s << endl;
            } else if (command == "find-max-segment") {                
                cout << *max_element(arr.begin() + i - 1, arr.begin() + j) << endl;
            }
        }
    }
};

int main() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    char c;
    cin >> c; 
    cin.ignore();

    Solution solution;
    solution.solve(a);
    return 0;
}
