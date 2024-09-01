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
#include <cassert>
#include <array>
#include <unordered_set>


using namespace std;
#define NDEBUG
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
const int MAX_N = 200'005;
const int INF = 1E9;

unordered_set<int> bfs(int start, unordered_map<int, vi>& tree, unordered_set<int>& needed) {
    queue<int> q;
    unordered_set<int> visited;
    unordered_set<int> subtree;
    unordered_map<int, int> parent;

    q.push(start);
    visited.insert(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        subtree.insert(node);
        
        // Explore all adjacent nodes
        for (int neighbor : tree[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    for (int v : needed) {
        int current = v;
        while (current != start && subtree.find(current) == subtree.end()) {
            subtree.insert(current);
            current = parent[current];
        }
        subtree.insert(start);  
    }
    return subtree; 
}


unordered_set<int> constructMinimalTree(unordered_map<int, vi>& tree, vi& V) {
    unordered_set<int> needed(V.begin(), V.end());  // Nodes that we need to include
    
    // Start BFS from the first node in V
    unordered_set<int> minimalTree = bfs(V[0], tree, needed);
    
    return minimalTree;
}


int32_t main() {
    ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin>>n>>k; 
    unordered_map<int, vi> tree(n); 

    for (int i = 0; i < n; i++) {
        int a, b; cin>>a>>b; 
        tree[a].pb(b);
        tree[b].pb(a);
    }

    vi v(k);
    for (int i = 0; i < k; i++) {
        cin>>v[i];
    }
    if (k == 1) cout<<v[0]<<endl; 
    else {
        unordered_set<int> minTree = constructMinimalTree(tree, v);
        cout<<sz(minTree)<<endl; 
    }
}