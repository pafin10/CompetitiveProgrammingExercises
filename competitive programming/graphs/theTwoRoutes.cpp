#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

constexpr int MAX_N = 400 + 5; 
constexpr int INF = 1E9;

int main() {
    // ifstream cin("theTwoRoutes.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> adj_rail[n], adj_road[n];
    bool bfs_rail = true;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj_rail[u].push_back(v);
        adj_rail[v].push_back(u);
        if ((u == 0 && v == n - 1) || (u == n - 1 && v == 0))
            bfs_rail = false;
    }

    bool pos = true;
    if (m == 0 || m == (n * (n - 1)) / 2) pos = false;

    bool vis[n];
    memset(vis, 0, sizeof(vis));
    vector<int> ans(n, INF);
    ans[0] = 0;

    queue<int> q;
    q.push(0);

    if (bfs_rail) {
        // BFS on adj_rail
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            vis[v] = true;

            for (int u : adj_rail[v]) {
                if (!vis[u] && ans[u] > ans[v] + 1) {
                    ans[u] = ans[v] + 1;
                    q.push(u);
                }
            }
        }
    } else {
        // Build adj_road
        // For faster check if edge exists, mark all rail edges
        bool is_rail[n][n];
        memset(is_rail, 0, sizeof(is_rail));
        for (int u = 0; u < n; ++u) {
            for (int v : adj_rail[u]) {
                is_rail[u][v] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!is_rail[i][j]) {
                    adj_road[i].push_back(j);
                    adj_road[j].push_back(i);
                }
            }
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            vis[v] = true;

            for (int u : adj_road[v]) {
                if (!vis[u] && ans[u] > ans[v] + 1) {
                    ans[u] = ans[v] + 1;
                    q.push(u);
                }
            }
        }
    }

    if (pos && ans[n - 1] != INF)
        cout << ans[n - 1] << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
