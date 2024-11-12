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

int32_t main() {
    //ifstream cin("speedBreaker.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n);

        vi l(n , n), r(n, -1);
        for (int i = 0; i < n; i++) {
            cin>>a[i];
            a[i]--;
            l[a[i]] = min(l[a[i]], i);
            r[a[i]] = max(r[a[i]], i);
        }

        vi f(n);
        int R = -1, L = n; 
        for (int i = 0; i < n; i++) {
            L = min(l[i], L);
            R = max(r[i], R);

            if (R - L <= i) {
                int l = max(R - i, 0); 
                int r = min(L + i, n - 1);
                f[l]++; 
                if (r < n - 1) f[r+1]--;
            }
        }

        for (int i = 1; i < n; i++) {
            f[i] += f[i-1];
        }
        int ans = count(f.begin(), f.end(), n);
        cout<<ans<<endl; 
    }
}