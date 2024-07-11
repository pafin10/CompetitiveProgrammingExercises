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
    //ifstream cin("gameWithReversing.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n;
        string s, r; cin>>s>>r;
        if (s == r) {cout<<0<<endl; continue;}
        
        int ans = 0;
        int diffCnt = 0, diffCntRev = 0;
        it(i,0,n) if (s[i] != r[i]) diffCnt++;
        reverse(all(r));
        it(i,0,n) if (s[i] != r[i]) diffCntRev++;
      
        int ans1 = 2 * diffCnt - diffCnt%2;
        int ans2 = 2 * diffCntRev;
        if (diffCntRev > 0 && diffCntRev % 2 == 0) ans2--;
        if (diffCntRev == 0) ans2 = 2;

        ans = min(ans1, ans2);

        cout<<ans<<endl; 
    }
}