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
#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;
const int MAXI = 1e9;

static int power(int k, int n) {
    int result = k;
    if (n == 0) return 1; 
    for (int i = 0; i < n; ++i) {
        result *= k;
    }
    return result;
}

static int count_pairs(int k, int n, int l1, int r1, int l2, int r2) {
    int k_n = power(k, n);
    // y
    int max_j = r2 / k_n; 
    int min_j = (l2 + 1) / k_n;
    // x
    int ans = max(0LL, min(r1, max_j) - max(l1, min_j)); 
    return ans; 
}

// CHECK TUTORIAL & OTHERS CODE
int32_t main() {
    ifstream cin("5.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int k, l1, r1, l2, r2; 
        cin>>k>>l1>>r1>>l2>>r2; 

        int ans = 0; 
        for (int i = 0; power(k, i) <= MAXI; i++) {
            ans += count_pairs(k, i, l1, r1, l2, r2);
        }
        cout<<ans<<endl; 
    }
}