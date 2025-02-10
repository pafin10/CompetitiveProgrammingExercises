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
vector<vector<array<int, 3>>> am; 

class DisjointUnionSets {
    vector<int> rank, parent;

public:
  
    // Constructor to initialize sets
    DisjointUnionSets(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        // Initially, each element is in its own set
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find the representative of the set that x belongs to
    int find(int x) {
        if (parent[x] != x) {
          
            // Path compression
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union of sets containing x and y
    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot) return;

        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
            am[yRoot].insert(am[yRoot].end(), am[xRoot].begin(), am[xRoot].end());
            am[xRoot].clear();
        } else {
            parent[yRoot] = xRoot;
            am[xRoot].insert(am[xRoot].end(), am[yRoot].begin(), am[yRoot].end());
            am[yRoot].clear();
            if (rank[xRoot] == rank[yRoot]) rank[xRoot]++;
        }
    }
public:
    void setParent(int x, int p) {
        parent[x] = p;
    }

    int getParent(int x) {
        return parent[x];
    }
};

int32_t main() {
    // ifstream cin("5.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin>>n>>m; 
    DisjointUnionSets uf(n);
    am.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b; 
        a--; b--; 
        if (uf.find(a) == uf.find(b)) am[uf.find(a)].push_back({a, b, i});
        else uf.unionSets(a, b);
    }

    // now we have the number of disjoint graphs
    // for each subgraph, connect one of its cables (the parent) to the parent of the adjacent subgraph

    vector<pair<int, int>> subgraphs;  
    for (int i = 0; i < n; i++) {
        if (uf.getParent(i) == i)
            subgraphs.push_back({am[i].size(), i}); // size of subgraph and parent
    }
    sort(subgraphs.rbegin(), subgraphs.rend());

    cout<< subgraphs.size() - 1 <<endl; 

    int pos = 1;
    
    for (auto [_, root] : subgraphs) {
        for (auto[a, b, i]: am[root]) {
            if (pos < subgraphs.size()) {
                cout<< i+1 << " " << a + 1 << " "<< subgraphs[pos++].second + 1 <<endl; 
            }
        }
    }


}