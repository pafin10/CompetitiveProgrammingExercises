#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <array>
#include <deque>
#include <functional>


using namespace std;
#define NDEBUG
#define endl "\n"
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int)x.size()
#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  

void dfs(int node, int target, vector<vector<pair<int, int>>>& adj, 
    int curr_xor, vector<bool>& visited, int& ans) {
    if (node == target) {
        ans = min(ans, curr_xor);
        return; 
    }

    visited[node] = true;  
    for (auto [k, w] : adj[node]) {
        if (!visited[k]) {  
            dfs(k, target, adj, curr_xor ^ w, visited, ans);
        }
    }
    visited[node] = false; 
}


int32_t main() {
    // IMPORTANT: XOR IS NON - MONOTONIC SO WE MUST ALLOW FOR FURTHER EXPLORATION
    // OF DIFFERENT PATHS!
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin>>n>>m; 
    vector<vector<pair<int, int>>> adj(n); 
    for (int i = 0; i < m; i++) {
        int u, v, w; cin>>u>>v>>w;
        u--; v--; 
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int ans = INT64_MAX;

    vector<bool> visited(n, false);
    dfs(0, n-1, adj, 0LL, visited, ans);

    cout<<ans<<endl; 
}