#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class database {
private:
    vector<string> Store;

    bool _find(string s) {
        return find(Store.begin(), Store.end(), s) != Store.end();
    }

    bool _insert(string s) {
        if (_find(s)) return false;
        Store.push_back(s);
        return true;
    }

public:
    void query(string q) {
        stringstream ss(q);
        string s1, s2;
        ss >> s1 >> s2;
        
        if (s1 == "find") {
            cout << _find(s2) << endl;
        } else if (s1 == "insert") {
            cout << _insert(s2) << endl;
        } else  {
            Store.push_back(s1);
        }
    }
};

int main() {
    database QL;
    string q;
    getline(cin, q);
    while(q != "*") {
        QL.query(q);
        fflush(stdin);
        getline(cin, q);
    }
    fflush(stdin);
    getline(cin, q);

    while(q != "***") {
        QL.query(q);
        fflush(stdin);
        getline(cin, q);
    }
    return 0;
}
