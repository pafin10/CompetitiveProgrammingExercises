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
#include <queue>
#include <unordered_map>
#include <cassert>
#include <array>
#include <deque>
#include <functional>
#include <stack>


using namespace std;
#define NDEBUG
#define endl "\n"
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int)x.size()
//#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  

void dfs(vector<vector<int>>& adj, int start, int end, vector<int>& parent) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> s; 
    s.push(start);
    parent[start] = -1;
    visited[start] = true;

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        if (u == end)  
            return;

        for (auto v: adj[u]) {
            visited[v] = true; 
            parent[v] = u;
            s.push(v);
        }
    }

}

vector<int> reconstructPath(int start, int end, vector<int>& parent) {
    vector<int> path; 
    for (int cur = end; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return path; 
}
int32_t main() {
    // CHECK SOL
    ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, st, en; 
        cin>>n>>st>>en; 
        st--; en--;
        vector<vector<int>> adj(n);

        for (int i = 0; i < n - 1; i++) {
            int a, b; cin>>a>>b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> parent(n, -1);
        dfs(adj, st, en, parent);
        vector<int> simple_path = reconstructPath(st, en, parent);
        vector<bool> on_path(n, false);

        for (auto u: simple_path) on_path[u] = true;
        int missing = n - simple_path.size();

        vector<int> p, start_sub, end_sub;
        
        vector<bool> vis_start(n, false), vis_end(n, false);
        for (auto u: adj[st]) {
            if (u != st && !vis_start[u]) start_sub.push_back(u);
            vis_start[u] = true; 
        }
    }
}