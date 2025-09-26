#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 10000; 
vector<vector<int>> capacity(MAXN, vector<int>(MAXN, 0));
vector<vector<int>> adj(MAXN);

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2; 
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) { 
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t) {
                    return new_flow; 
                }
                q.push({next, new_flow});
            }
        }
    }
    
    return 0; 
}

int maxFlow(int s, int t, int n) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;
    
    while ((new_flow = bfs(s, t, parent)) != 0) {
        flow += new_flow;
        int cur = t;
        
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    
    return flow;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int s, t;
    cin >> s >> t;
    s--; t--;
    
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--; 
        capacity[u][v] += c; 
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    
    cout << maxFlow(s, t, n) << endl;
    
    return 0;
}
