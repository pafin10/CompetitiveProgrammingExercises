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
#define int long long
const int MAX_N = 100'005;

int32_t main() {
    //ifstream cin("threeActivities.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<pii> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) {
            cin>>a[i].ff;
            a[i].ss = i;
        }
        for (int i = 0; i < n; i++) {
            cin>>b[i].ff;
            b[i].ss = i;
        }
        for (int i = 0; i < n; i++) {
            cin>>c[i].ff;
            c[i].ss = i;
        }
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        sort(c.rbegin(), c.rend());

        int ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (a[i].ss != b[j].ss && a[i].ss != c[k].ss && b[j].ss != c[k].ss) {
                        ans = max(ans, a[i].ff + b[j].ff + c[k].ff);
                    }
                }
            }
        }
        cout<<ans<<endl; 
        

        


    }
}