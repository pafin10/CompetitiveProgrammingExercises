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


int32_t main() {
    // ifstream cin("5.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n; 

    map<int, int> m; 
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        int u; cin>>u; 
        int v; cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        m[u] = 1; m[v] = 0; 
    }

    int missing = 0; 
    for (auto p: m) {
        if (p.second) {
            missing += (n - 1) - adj[p.first].size();
        }
    }
    bool first = true; 
    if (missing % 2 == 0) cout<<"First"<<endl; 
    else {
        cout<<"Second"<<endl; 
        first = false; 
    }

    int i, j; 
    if (first) {
        for (auto p: m) {
            if (p.second) {
                for (auto k: m) {
                    if (!k.second) {
                        for (auto v: adj[p.first]) if (v == k.first) continue;
                        i = p.first; j = k.first;
                    }
                }
            }
        }
        adj[i].push_back(j);
        adj[j].push_back(i);
        cout<<i<<" "<<j<<endl; 
        cout.flush();
    } 

    while (i != -1 && j != -1) {
        cin>>i; 
        cin>>j; 
        adj[i].push_back(j);
        adj[j].push_back(i);

        for (auto p: m) {
            if (p.second) {
                for (auto k: m) {
                    if (!k.second) {
                        for (auto v: adj[p.first]) if (v == k.first) continue;
                        i = p.first; j = k.first;
                    }
                }
            }
        }
        adj[i].push_back(j);
        adj[j].push_back(i);

        cout<<i<<" "<<j<<endl; 
        cout.flush();
    }

}