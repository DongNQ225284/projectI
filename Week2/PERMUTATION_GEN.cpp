//C++ 
#include <bits/stdc++.h> 
using namespace std;

int n;
vector<int> a;

int loop(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

void print() {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() { 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    
    for (int i = 1; i < loop(n); i++) {
        print();
        next_permutation(a.begin(), a.end());
    }
    print();
    return 0;
}
