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
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 
        vector<int> a(n);

        for (auto& i: a) cin>>i; 

        int ans = 0, groups = 1;
        int cnt = 1, pos = INT32_MAX; 
        for (int i = 1; i < n; i++) {
            if (a[i] != cnt) {
                pos = i; 
                break; 
            }
        }
        if (n - pos >= k - 1) ans = 1;
        else {
            vector<bool> use(n, true);
            for (int i = 1; i < n; i++) {
                if (a[i] == cnt) {
                    use[i] = false; 
                    cnt++;
                }
            }
            bool first = true; 
            int start = -1;
            for (int i = 1; i < n; i++) {
                if (first && !use[i]) {
                    start = i; first = false; 
                }
                else if (!first && use[i]) {
                    groups++;
                    // check if one group of this size is possible
                    int group_size = i - start + 1;
                    if (n - group_size >= k - groups) { // one group for even start, one current
                        ans = groups - 1;
                    }
                }
            }
        }
        if (n == k) ans = n / 2 + 1;
        cout<<ans<<endl; 
        
    }
}