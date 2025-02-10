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
    ifstream cin("5.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin>>n>>m; 

    DisjointUnionSets uf(n);

    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        uf.unionSets(a, b);
    }

    int components = 0;

    set<int> parents;
    for (int i = 1; i <= n; i++) {
        parents.insert(uf.getParent(i));
    }
    // would have to map cable numbers (of initial edges) back to connections within subgraph
    cout<<(int)parents.size() - 1<<endl; 
    vector<int> p(parents.begin(), parents.end());

    vector<pair<int, pair<int, int>>> ans(parents.size() - 1); 
    for (int i = 1; i < p.size(); i++) {
        ans[i - 1] = {p[i], {p[i - 1], p[i]}};
    }

    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
    }
    
}

