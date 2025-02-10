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
#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  


int32_t main() {
    // ifstream cin("addZeros.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n);

        for (auto& i: a) cin>>i;

        map<int, vector<int>> adj; 
        for (int i = 1; i < n; i++) {
            int u = a[i] + i; 
            int v = u + i;
            adj[u].push_back(v);
        }

        set<int> vis; 
        function<void(int)> dfs = [&](int u) -> void {
            if (vis.count(u)) return; 
            vis.insert(u);
            for (auto v: adj[u]) dfs(v);
        };
        dfs(n);
        cout<<*vis.rbegin()<<endl; 
    }
}