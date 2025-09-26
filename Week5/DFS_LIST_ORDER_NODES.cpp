#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
    stack<int> s;
    s.push(start);
    
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        
        if (!visited[node]) {
            visited[node] = true;
            result.push_back(node);
            
            for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> result;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(1, adj, visited, result);

    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
