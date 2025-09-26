#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> a;
    int n, M;
    cin >> n >> M;
    for (int i = 0; i < n; i++) {
        int e; cin >> e;
        a.push_back(e);
    }

    sort(a.begin(), a.end());

    int count = 0;
    int L = 0, R = n - 1;
    while(L != R) {
        if (a[L] + a[R] == M) {
            count++;
            L++;
            R--;
        } else if (a[L] + a[R] < M) {
            L++;
        } else if (a[L] + a[R] > M) {
            R--;
        }
    }
    cout << count << endl;
    return 0;
}
