#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <array>
#include <utility>


using namespace std;
#define NDEBUG
#define ll long long
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define int long long

const int MAX_N = 100'005;
const int INF = 1E9;
bool vis[2 * MAX_N];
int d[2 * MAX_N];
vector<pii> adj[2 * MAX_N];


void dfs(int u, int dis) {
    
    vis[u] = 1; d[u] = dis;
    for (auto [k , w] : adj[u]) {
        if (vis[k]) continue;
        dfs(k, dis + w);
    }  
}

int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; 
    cin>>n>>m; 

    for (int i = 1; i <= m; i++) {
        int u, v, w; 
        cin>>u>>v>>w; 
        adj[u].pb({v, w});
        adj[v].pb({u, -w});
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, 0);
    }
    for (int i = 1; i <= n; i++) {
        cout<<d[i]<<" ";
    }
    cout<<endl; 
}