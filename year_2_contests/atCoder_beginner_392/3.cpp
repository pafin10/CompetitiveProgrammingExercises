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
    
    int n; cin>>n; 
    vector<int> p(n + 1), q(n + 1);

    for (int i = 1; i <= n; i++) cin>>p[i]; 
    for (int i = 1; i <= n; i++) cin>>q[i]; 

    map<int, int> m, ans; 
    for (int i = 1; i <= n; i++) {
        m[p[i]] = q[p[i]];
    }
    
    for (int i = 1; i <= n; i++) {
        ans[q[i]] = m[p[i]];
    }

    for (auto p: ans) cout<<p.second<<" ";
    cout<<endl; 

}