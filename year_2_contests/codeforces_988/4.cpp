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
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

     while (t--) {
        int n, m, L;
        cin >> n >> m >> L;
        vector<pii> hurdles(n + 1), power_ups(m + 1);

        for (int i = 1; i <= n; i++) {
            cin >> hurdles[i].ff >> hurdles[i].ss;
        }
        for (int i = 1; i <= m; i++) {
            cin >> power_ups[i].ff >> power_ups[i].ss;
        }

        int ans = 0, jp = 1, j = 1, k = 1;
        vector<int> jps(n + 1);

        // Forward 
        for (int i = 1; i <= L; i++) {
            if (j <= n && i == hurdles[j].ff - 1) {
                jps[j] = jp;
                if (i + jp <= hurdles[j].ss) {
                    ans = -1;
                    break;
                }
                j++;
            }

            while (i <= hurdles[n].ff && k <= m && i == power_ups[k].ff) {
                jp += power_ups[k].ss;
                ans++;
                k++;
            }
        }

        // Backward 
        j = n;
        k = m;
        for (int i = L; i >= 1; i--) {
            if (i == hurdles[j].ff - 1) {
                auto start = lower_bound(power_ups.begin(), power_ups.end(), make_pair(hurdles[j - 1].ss + 1, INT_MIN));
                auto end = upper_bound(power_ups.begin(), power_ups.end(), make_pair(hurdles[j].ff, INT_MAX));

                vector<pii> power_ups_in_region(start, end);
                sort(power_ups_in_region.begin(), power_ups_in_region.end(), 
                     [](const pii &a, const pii &b) { return a.second < b.second; });

                int g = 0;
                while (g < power_ups_in_region.size() && j > 0 && 
                (jps[j] - power_ups_in_region[g].ss) > (hurdles[j].ss - hurdles[j].ff + 1)) {
                    if (ans) ans--;
                    jps[j] -= power_ups_in_region[g].ss;
                    g++;
                }
                j--;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
