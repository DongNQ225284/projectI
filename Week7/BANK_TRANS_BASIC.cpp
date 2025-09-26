#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Transaction {
    string from_account;
    string to_account;
    int money;
    string time_point;
    string atm;
};

unordered_map<string, int> account_money;
unordered_map<string, unordered_set<string>> transaction_map;
vector<Transaction> transactions;

bool check_cycle(const string& start_account, int k, unordered_set<string>& visited, const string& current_account, int length) {
    if (length == k) {
        return current_account == start_account;
    }
    
    if (visited.count(current_account)) {
        return false;
    }

    visited.insert(current_account);
    
    for (const string& next_account : transaction_map[current_account]) {
        if (check_cycle(start_account, k, visited, next_account, length + 1)) {
            return true;
        }
    }
    
    visited.erase(current_account);
    return false;
}

int main() {
    string line;
   
    while (getline(cin, line)) {
        if (line == "#") {
            break;
        }
        
        stringstream ss(line);
        Transaction t;
        ss >> t.from_account >> t.to_account >> t.money >> t.time_point >> t.atm;
  
        transactions.push_back(t);
      
        account_money[t.from_account] += t.money;
 
        transaction_map[t.from_account].insert(t.to_account);
    }
    
    while (getline(cin, line)) {
        if (line == "#") {
            break;
        }

        stringstream ss(line);
        string query;
        ss >> query;
        
        if (query == "?number_transactions") {
            cout << transactions.size() << endl;
        }
        else if (query == "?total_money_transaction") {
            int total_money = 0;
            for (const auto& t : transactions) {
                total_money += t.money;
            }
            cout << total_money << endl;
        }
        else if (query == "?list_sorted_accounts") {
            unordered_set<string> account_set;
            for (const auto& t : transactions) {
                account_set.insert(t.from_account);
                account_set.insert(t.to_account);
            }
            vector<string> sorted_accounts(account_set.begin(), account_set.end());
            sort(sorted_accounts.begin(), sorted_accounts.end());
            
            for (const string& account : sorted_accounts) {
                cout << account << endl;
            }
        }
        else if (query == "?total_money_transaction_from") {
            string account;
            ss >> account;
            cout << account_money[account] << endl;
        }
        else if (query == "?inspect_cycle") {
            string account;
            int k;
            ss >> account >> k;
            unordered_set<string> visited;
            bool found_cycle = check_cycle(account, k, visited, account, 0);
            cout << (found_cycle ? 1 : 0) << endl;
        }
    }
    
    return 0;
}
