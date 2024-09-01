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

int32_t main() {
    //ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, t; cin>>n>>t; 
    string s; cin>>s; 
    vi pos, neg;
    it(i,0,n) {
        int j; cin>>j; 
        s[i] == '0' ? neg.pb(j) : pos.pb(j);
    }

    sort(all(pos));
    sort(all(neg));

     int ans = 0;

    for (auto& x : pos) {
        auto it = upper_bound(all(neg), x + 2*t) - neg.begin();
        auto jt = upper_bound(all(neg), x) - neg.begin();
        ans += it-jt;
    }

    cout << ans << endl;




}