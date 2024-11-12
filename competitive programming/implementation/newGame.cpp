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
    ifstream cin("newGame.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 
        vi a(n);

        for (auto& i : a) cin>>i; 
        sort(a.begin(), a.end());

        vi curr; 
        int diffCnt = 1, ans = 0;
        int start = 0; 
        curr.pb(a[0]);

        for (int i = 1; i < n; i++) {

            if (a[i] - a[i-1] == 1) {
                diffCnt++;
                if (diffCnt > k) {
                    i = start;
                    diffCnt = 1; 
                    ans = max(ans, (int) curr.size());
                    curr.clear();
                }
                else start = i; 
            }

            else if (a[i] - a[i - 1] > 1) {
                start = i; 
                ans = max(ans, (int) curr.size());
                curr.clear();
                diffCnt = 1;
            }
            curr.pb(a[i]);
        }

        cout<<ans<<endl; 
    }
}