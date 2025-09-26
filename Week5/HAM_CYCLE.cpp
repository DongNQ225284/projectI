#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool isHamiltonianCycle(int start, int pos, vector<vector<int>> &graph, vector<bool> &visited, int n) {
    if (pos == n) {
        if (graph[start][0] == 1) return true;
        else return false;
    }

    for (int v = 1; v < n; v++) {
        if (graph[start][v] == 1 && !visited[v]) {
            visited[v] = true;
            if (isHamiltonianCycle(v, pos + 1, graph, visited, n)) return true;
            visited[v] = false;
        }
    }
    return false;
}

bool checkHamiltonian(int n, vector<vector<int>> &graph) {
    vector<bool> visited(n, false);
    visited[0] = true; 

    return isHamiltonianCycle(0, 1, graph, visited, n);
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n, vector<int>(n, 0));

        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            u--; v--; 
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        cout << checkHamiltonian(n, graph) << endl;
    }

    return 0;
}
