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
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m; 
        string s; cin>>s;
        vi a(m); 
        it(i,0,m) {cin>>a[i]; a[i]--;}
        string c; cin>>c; 

        vector<char> ans(all(s));
        sort(all(c));
        sort(all(a));

        int i = 0, last = -1;
        int j = 0;
        while (j < m) {
            if (a[j] != last) {ans[a[j]] = c[i]; i++;}
            last = a[j]; j++;
        }
        for (auto& k : ans) cout<<k;
        cout<<endl; 

    }
}