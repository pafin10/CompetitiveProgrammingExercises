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


using namespace std;
#define NDEBUG
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
#define int long long
const int MAX_N = 100'005;
const int INF = 1e9;


int32_t main() {
    //ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

   while (t--) {
        int n;
        cin >> n;

        vi a(n);
        vector<vi> children(n + 1);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // save children nodes
        for (int i = 1; i < n; ++i) {
            int p;
            cin >> p;
            children[p-1].pb(i);
        }

        // check recursively if a number x can become the max value of the root by checking if all
        // subtrees support it. 
        auto check = [&](auto&& self, int v, int x) -> bool {
            if (x > INF) return false; 
            bool isLeaf = true; 
            if (v) x += max(0LL, x - a[v]);
            for (auto e : children[v]) {
                isLeaf = false; 
                if (!self(self, e, x)) return false; 
            }
            return (!isLeaf || x <= a[v]);
        };

        // use binary search between max possible val and 1
        int l = 1, r = INF; 
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(check, 0, mid)) {
                l = mid + 1;
            }
            else r = mid - 1;
        }

        // ans is initial value + binary search result
        cout << a[0] + l - 1 << endl;
    }

    return 0;
}