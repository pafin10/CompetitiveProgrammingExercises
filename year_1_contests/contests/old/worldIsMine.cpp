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
//#define int long long
const int MAX_N = 100'005;

int32_t main() {
    ifstream cin("worldIsMine.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }

        sort(all(a));
        vi nxt(n+1);
        nxt[n] = n;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && a[i] != a[i+1]) {
                nxt[i] = i + 1;
            }
            else {
                nxt[i] = nxt[i+1];
            }
        }
        const int inf(1e9);
        // f[i][j] is minimum number of cakes alice can eat if j are left (probably)
        vector<vi> f(n+1, vi(n+1, inf));
        // when n cakes are eaten, there are no cakes left for alice to eat
        for (int i = 0; i <= n; i++) {
            f[n][i] = 0;
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                // alice eats current cake and moves to next distinct, bob has then eaten j+1 afterwards
                f[i][j] = f[nxt[i]][min(n, j+1)] + 1;
                if (j > 0) {
                    // bob eats current cake and alice starts from next
                    f[i][j] = min(f[i][j], f[i+1][j-1]);
                }
            }
        }
        cout<<f[0][0]<<endl; 

    }
}