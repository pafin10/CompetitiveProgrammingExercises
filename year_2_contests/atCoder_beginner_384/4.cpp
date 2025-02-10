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
#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;

// Fails in a few cases, whats the issue??

int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s; cin>>n>>s; 
    vi a(n);
    
    int sum_n = 0; 
    bool fd = false; 
    for (auto& i: a) {
        cin>>i; 
        if (i == s) fd = true; 
        sum_n += i; 
    }
    if (fd) {
        cout<<"Yes"<<endl; 
        return 0; 
    }
    
    a.insert(a.end(), a.begin(), a.end());
    if (s > 2 * sum_n) {
        int tmp = s / sum_n - 1;
        s -= tmp * sum_n;
    }
    // now find exact s in a 

    string ans = "No"; 
    int l = 0, r = 1;
    int run_sum = a[l]; 

    while (l < n) {
        while (r < 2 * n && run_sum < s) {
            run_sum += a[r];
            r++;
        }
        if (run_sum == s) {
            ans = "Yes";
            break;
        }
        run_sum -= a[l];
        l++;
    }

    if (!fd) cout<<ans<<endl; 
}