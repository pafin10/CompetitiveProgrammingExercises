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

int ans;
void operate(vector<int>& a, int n) {
    int mad = 0; 
    map<int, int> m; 

    for (int i = 1; i <= n; i++) {
        int val = a[i];
        ans += val;
        m[val]++;
        if (m[val] >= 2) mad = max(mad, val);
        a[i] = mad; 
    }
}

int32_t main() {
    // ifstream cin("madMADsum.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++) cin>>a[i];
        ans = 0; 

        operate(a, n); 
        operate(a, n);

        
        for (int i = 1; i <= n; i++) ans += a[i] * 1LL * (n - i + 1);
        cout<<ans<<endl; 
    }
}