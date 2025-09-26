//C++ 
#include <bits/stdc++.h> 
using namespace std;

int main() { 
    int n;
    vector<int> a = {0, 1};
    
    cin >> n;
    for (int i = 2; i < n; i++) {
        a.push_back(a[i -  2] + a[i - 1]);
    }
    
    cout << a[n - 1] << endl;
}
