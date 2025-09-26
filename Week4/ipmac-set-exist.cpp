#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int,int>> a;
    for (int i = 0; i < n; i++) {
        int e; cin >> e;
        a.push_back(make_pair(e, i));
    }

    sort(a.begin(), a.end(), [](pair<int,int> a, pair<int,int> b) {
        if (a.first == b.first) return a.second < b.second;
        else return a.first < b.first;
    });

    vector<pair<int,int>> m;
    m.push_back(make_pair(a[0].second, 0));
    for (int i = 1; i < n; i++) {
        int e1 = a[i].second;
        int e2 = ((a[i].first == a[i - 1].first) && (a[i].second > a[i - 1].second));
        m.push_back(make_pair(e1, e2));
    }
    
    sort(m.begin(), m.end());

    for (int i = 0; i < n; i++) {
        cout << m[i].second << endl;
    }

    return 0;
}
