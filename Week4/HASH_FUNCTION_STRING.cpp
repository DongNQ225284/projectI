#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define toInt(char) (char - 0)

int H(string s, int m) {
    int k = s.length();
    int sum = 0;
    int coeffi = 1;
    for (int i = 0; i < k; i++) {
        sum += toInt(s[k - i - 1]) * coeffi;
        coeffi *= 256;
        coeffi %= m;
        sum %= m; 
    }
    return sum;
}

int main() {
    int n, m; cin >> n >> m;
    
    while(n--) {
       string s;
       cin >> s;
       cout << H(s, m) << endl;
    }
    return 0;
}
