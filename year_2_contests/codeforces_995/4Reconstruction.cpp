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


int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, x, y; 
        cin>>n>>x>>y; 

        vector<int> a(n);
        for (auto& i : a) cin>>i; 

        sort(a.begin(), a.end());
        int sum = accumulate(a.begin(), a.end(), 0LL);
        int px = sum - y, py = sum - x; 
        int ans = 0; 

        for (int i = 0, x = n, y = n; i < n; i++) {
            while (x > 0 && a[i] + a[x - 1] >= px) x--;
            while (y > 0 && a[i] + a[y - 1] > py) y--;
            
            ans += max(y, i + 1) - max(x, i + 1);
        }
        cout<<ans<<endl; 
    }
}