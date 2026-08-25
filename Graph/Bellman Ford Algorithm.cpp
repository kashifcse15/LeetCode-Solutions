#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src) {
    vector<int> dist(V, 1e8);

    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycle
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return {-1};   // Negative cycle exists
        }
    }

    return dist;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    vector<int> ans = bellmanFord(V, edges, 0);

    if (ans.size() == 1 && ans[0] == -1) {
        cout << "Negative Weight Cycle Exists";
    } else {
        for (int d : ans)
            cout << d << " ";
    }
}
