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
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;
int subtree_size[100001];

void dfs(int node, int parent, const vector<vi>& children) {
    subtree_size[node] = 1; 

    for (int child : children[node]) {
        if (child != parent) {
            dfs(child, node, children);
            subtree_size[node] += subtree_size[child];
        }
    }
}

int32_t main() {
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t = 1;//cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<vi> edges(n - 1);
        for (auto& edge : edges) {
            int a, b; cin>>a>>b; 
            if (a > b) swap(a, b);
            a--; b--;
            edge.pb(a);
            edge.pb(b);
        }
        int x, y; 
        cin>>x>>y; 

        sort(edges.begin(), edges.end());

        vector<vi> children(n);
        for (auto& edge : edges) {
            children[edge[0]].pb(edge[1]);
            children[edge[1]].pb(edge[0]);
        }

        int root = 0;
        dfs(root, -1, children);

        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (subtree_size[i] == x) a++;
            else if (subtree_size[i] == y) b++;
        }
        cout<<a * b<<endl; 

    }
}