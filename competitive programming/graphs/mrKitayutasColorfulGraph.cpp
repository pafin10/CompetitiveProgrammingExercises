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
bool vis[100];
vector<int> adj[100][100];


void dfs(int u, int c) {
    vis[u] = true; 
    for (auto v: adj[u][c]) {
        if (!vis[v]) {
            dfs(v, c);
        }
    }
}

int32_t main() {
    // ifstream cin("mrKitayutasColorfulGraph.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin>>n>>m; 

    for (int i = 0; i < m; i++) {
        int u, v, c; 
        cin>>u>>v>>c;
        u--; v--; c--;

        adj[u][c].push_back(v);
        adj[v][c].push_back(u);
    }

    int q; cin>>q;
    int cnt = 0; 
    for (int i = 0; i < q; i++) {
        cnt = 0; 
        int a, b; cin>>a>>b;
        a--; b--; 

        for (int c = 0; c < m; c++) {
            for (int k = 0; k < n; k++) vis[k] = false; 
            dfs(a, c);
            if (vis[b]) cnt++;
        }
        cout<<cnt<<endl; 
    }
}