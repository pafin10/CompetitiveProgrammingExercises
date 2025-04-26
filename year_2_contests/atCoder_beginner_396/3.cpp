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
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin>>n>>m; 
    vector<int> b(n), w(m);

    for (int i = 0; i < n; i++) cin>>b[i];
    for (int i = 0; i < m; i++) cin>>w[i];

    sort(b.rbegin(), b.rend());
    sort(w.rbegin(), w.rend());

    bool passed = true; 
    int ans = 0;
    bool last_white = false; 
    int ind = -1;
    for (int i = 0; i < min(n, m); i++) {
        if (b[i] >= 0 && w[i] >= 0) {
            ans += b[i]; ans += w[i];
        }
        else if (b[i] <= 0 && w[i] > 0 && (abs(w[i]) - abs(b[i])) > 0) {
            ans += b[i]; ans += w[i];
        }
        else {
            if (w[i] < 0) last_white = true; 
            ind = i; 
            passed = false;
            break;  
        }
    }
    if (passed) {
        if (n > m) {
            int cur = m;
            while (cur < n && b[cur] >= 0) {
                ans += b[cur++]; 
            }
        }
    }
    else {
        if (last_white) {
            int cur = ind;
            while (cur < n && b[cur] >= 0) {
                ans += b[cur++]; 
            }
        }
    }
    cout<<ans<<endl; 
}