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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t; 
    while(t--) {
        int n, m; cin>>n>>m;
        if (m == 0) {cout<<n<<endl; continue;}
        int l = max(0, n-m), r = n+m; 
        int ans = 0;
        itb(i , 30, 0) {
            int mask = (1 << i); 
            ans |= (mask & l); 
            ans |= (mask & r);
            if (r - l > (mask)) ans |= mask; 
        }
        cout<<ans<<endl; 
    }
}