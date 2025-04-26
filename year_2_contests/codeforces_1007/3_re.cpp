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
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, st, en; 
        cin>>n>>st>>en;
        st--; en--;

        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int a,b; cin>>a>>b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> vis(n, false);
        vector<int> que(1, en);
        vis[en] = true;

        for (int b = 0; b < (int)que.size(); b++) {
            for (auto to: adj[que[b]]) {
                if (!vis[to]) {
                    vis[to] = true;
                    que.push_back(to);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) cout<<que[i] + 1<<" ";
        cout<<endl; 
    }
}