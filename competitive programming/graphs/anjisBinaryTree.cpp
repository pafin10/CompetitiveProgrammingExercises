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
#include <deque>


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
const int INF = 1E9;
pair<int, int> tree[300005];
string s;

int dfs(int x = 1) {
    if (!tree[x].first && !tree[x].second) return 0;

    int res1 = 1e9; 
    if (tree[x].first) res1 = dfs(tree[x].first);
    if (s[x - 1] != 'L') res1++;

    int res2 = 1e9;
    if (tree[x].second) res2 = dfs(tree[x].second);
    if (s[x - 1] != 'R') res2++;

    return min(res1, res2);
}

int32_t main() {
    // ifstream cin("anjisBinaryTree.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        cin>>s;

        for (int i = 1; i <= n; i++) {
            cin>>tree[i].first>>tree[i].second;
        }
        
        cout<< dfs(1) <<endl;  
    }
}