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
#include <unordered_set>
#include <cassert>
#include <array>
#include <deque>
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
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;

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

        // If they are in the same set, no need to union
        if (xRoot == yRoot) return;

        // Union by rank
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[yRoot] < rank[xRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
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
    int t; cin>>t; 

    while(t--) {
        int n, m1, m2; 
        cin>>n>>m1>>m2;
        vector<pair<int, int>> edges;
        DisjointUnionSets uf_G(n), uf_F(n);
        
        for (int i = 0; i < m1; i++) {
            int a, b; cin>>a>>b; 
            edges.push_back({a, b});
        }
        for (int i = 0; i < m2; i++) {
            int a, b; cin>>a>>b; 
            uf_G.unionSets(a, b);
        }

        int ops = 0; 
        set<pair<int, int>> to_remove;
        for (auto& edge: edges) {
            if (uf_G.find(edge.first) != uf_G.find(edge.second)) {
                ops++;
                to_remove.insert({edge});
            }
        }

        // Remove edges from the edge list
        edges.erase(remove_if(edges.begin(), edges.end(),
                              [&](const pair<int, int>& edge) {
                                  return to_remove.count(edge);
                              }),
                    edges.end());

        // now we have no paths in F <-> no paths in G

        for (auto& edge: edges) {
            uf_F.unionSets(edge.first, edge.second);
        }
        set<int> components_G, components_F; 
        for (int i = 1; i <= n; i++) {
            components_F.insert(uf_F.find(i));
            components_G.insert(uf_G.find(i));
        }
        ops += abs((int)components_F.size() - (int)components_G.size());
        
        cout<<ops<<endl; 
    }
}