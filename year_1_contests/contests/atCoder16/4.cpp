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
    //ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<vector<vi>> a(n, vector<vi>(n, vi(n)));
    vector<vector<vi>> sums(n, vector<vi>(n, vi(n)));

    int runSum = 0;
    // inclusion exclusion !
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> a[i][j][k];
                sums[i][j][k] = a[i][j][k];
                
                if (i) sums[i][j][k] += sums[i-1][j][k];
                if (j) sums[i][j][k] += sums[i][j-1][k];
                if (k) sums[i][j][k] += sums[i][j][k-1];

                if (i && j) sums[i][j][k] -= sums[i-1][j-1][k];
                if (i && k) sums[i][j][k] -= sums[i-1][j][k-1];
                if (j && k) sums[i][j][k] -= sums[i][j-1][k-1];

                if (i && j && k ) sums[i][j][k] += sums[i-1][j-1][k-1];
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        lx--; rx--; ly--; ry--; lz--; rz--;

        int ans = sums[rx][ry][rz];
        
        if (lx) ans -= sums[lx-1][ry][rz];
        if (ly) ans -= sums[rx][ly-1][rz];
        if (lz) ans -= sums[rx][ry][lz-1];

        if (lx&& ly) ans += sums[lx-1][ly-1][rz];
        if (lx&& lz) ans += sums[lx-1][ry][lz-1];
        if (ly && lz ) ans += sums[rx][ly-1][lz-1];

        if (lx && ly && lz ) ans -= sums[lx-1][ly-1][lz-1];

        cout << ans << endl;
    }
}