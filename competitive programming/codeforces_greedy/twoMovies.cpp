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
    //ifstream cin("twoMovies.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n), b(n);
        int mov1 = 0, mov2 = 0;
        int neg = 0, pos = 0; 

        it(i,0,n) cin>>a[i];
        it(i,0,n) cin>>b[i];

        it(i,0,n) {
            if (a[i] > b[i]) mov1 += a[i];
            else if (b[i] > a[i]) mov2 += b[i];
            if (a[i] == b[i]) {
                if (a[i] == 1) pos++;
                else if (a[i] == -1) neg++;
            }
        }

        int ans = INT32_MIN;
        it(i,-neg,pos+1) {
            ans = max(ans, min(mov1 + i, mov2 + (pos - i - neg)));
        }
        
        cout<<ans<<endl; 

    }
}