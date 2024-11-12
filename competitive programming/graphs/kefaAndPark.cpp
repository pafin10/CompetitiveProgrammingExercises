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
#include <queue>
#include <unordered_map>
#include <cstring>
#include <stack>


using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define itb(i, start, n) for (int i = start; i >= n; --i)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
//#define int long long
const int MAX_N = 100'005;
bool visited[MAX_N];

void dfs(int u, const vector<vi>& children, const vi& cats, int cat_cnt, 
int& ans, int m, int parent) {
    
    if (cats[u]) cat_cnt++;
    else cat_cnt = 0;

    if (cat_cnt > m) return;  // Stop early if cat count exceeds m

    bool isLeaf = true;
    for (auto child : children[u]) {
        if (child != parent) {
            isLeaf = false;
            dfs(child, children, cats, cat_cnt, ans, m, u);
        }  
    }

    if (isLeaf) {  
        if (cat_cnt <= m) ans++;
    }
}

int32_t main() {
    //ifstream cin("kefaAndPark.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin>>n>>m; 
    vi cats(n);

    for (auto& cat : cats) {
        cin>>cat;
    }
    vector<pii> edges(n-1); 
    for (auto& edge : edges) {
        cin>>edge.ff;
        cin>>edge.ss;
        edge.ff--; edge.ss--;
        if (edge.ss < edge.ff) swap(edge.ss, edge.ff);
    }
    
    // CONSTRUCT TREE
    vector<vi> children(n); 
    for (auto& edge: edges) {
        int u = edge.ff, v = edge.ss;
        children[u].pb(v);
        children[v].pb(u);
    }

    // DFS TO FIND ANS
    memset(visited, false, sizeof(visited));
    int ans = 0;
    dfs(0, children, cats, 0, ans, m, -1);

    cout<<ans<<endl; 

}