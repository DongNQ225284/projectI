/*
Problem: Solve degree-2 polynomial equation

Description:
Given an equation ax^2 + bx + c = 0. Find solution to the given equation.
Input
Line 1 contains 3 integers a, b, c 
Output
Write NO SOLUTION if the given equation has no solution 
Write x0 (2 digits after the decimal point) if the given equation has one solution x0 
Write x1 and x2 with x1 < x2 (2 digits after the decimal point) if the given equation has two distinct solutions x1, x2 

*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void solve(double a, double b, double c) { 
        if (a == 0) {
            if (b == 0) {
                cout << "NO SOLUTION" << endl;
            } else {
                double x = -c / b;
                printf("%.2lf", x);
            }
            return;
        }

        double delta = b*b - 4*a*c;
        if (delta < 0) {
            cout << "NO SOLUTION" << endl;
        } else if (delta == 0) {
            double x = -b / (2*a);
            printf("%.2lf", x);
        } else {
            double sqrt_delta = sqrt(delta);
            double x1 = (-b - sqrt_delta) / (2*a);
            double x2 = (-b + sqrt_delta) / (2*a);
            if (x1 > x2) swap(x1, x2);
            printf("%.2lf %.2lf", x1, x2);
        }
    }
};

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    Solution solution = Solution();
    solution.solve(a, b, c);
    return 0;
}
