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

bool check(int k, string s, int n) {

    vector<bool> free(n, false);
    int free_cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            free_cnt++;
            if (free_cnt <= k) free[i] = true;
            else break; 
        }
    }

    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (free[i]) {
            cur--;
            if (cur < 0) return false; 
        }
        else cur++;
    }
    return true; 
}

int32_t main() {
    // ifstream cin("actionFigures.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string s; cin>>s; 

        if (n == 1) {
            cout<<1<<endl;
            continue;
        }
        int ones = 0;
        for (auto x: s) if (x == '1') ones++;

        int l = 1, r = ones + 1;
        int k = (l + r) / 2;

        while (r - l > 1) {
            k = (l + r) / 2;
            if (check(k, s, n))
                l = k;
            else 
                r = k;
        }

        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (l && s[i] == '1') {
                l--;
            }
            else ans += (i + 1);
        }
        cout<<ans<<endl; 
    }
}