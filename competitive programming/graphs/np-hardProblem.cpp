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
bool pos = true;
int color[MAX_N];
vector<int> adj[MAX_N];

void dfs(int u) {
    for (auto v: adj[u]) {
        if (!color[v]) {
            color[v] = 3 - color[u];
            dfs(v);
        }
        else if (color[v] == color[u]) {
            pos = false; 
            return; 
        }
    }
}

int32_t main() {
    // ifstream cin("np-hardProblem.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin>>n>>m; 
    
    for (int i = 0; i < m; i++) {
        int u, v; cin>>u>>v; 
        u--; v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int v = 0; v < n; v++) {
        if (!pos) break;
        if (!color[v]) {
            color[v] = 1;
            dfs(v);
        }
    }
    
    if (!pos) cout<<-1<<endl; 
    else {
        int red = count(color, color + n, 1);
        int blue = n - red; 

        cout<<red<<endl; 
        for (int i = 0; i < n; i++) {
            if (color[i] == 1) cout<<(i + 1)<<" ";
        }
        cout<<endl; 
        cout<<blue<<endl; 
        for (int i = 0; i < n; i++) {
            if (color[i] == 2) cout<<(i + 1)<<" ";
        }
    }
    
}