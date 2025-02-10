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
#include <deque>


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
    // ifstream cin("bessiesBirthdayCake(easy).txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, x, y; cin>>n>>x>>y;
        vector<int> a(x);

        for (int i = 0; i < x; i++) cin>>a[i];

        sort(a.begin(), a.end());

        int ans = x - 2;
        for (int i = 1; i < x; i++) {
            if (a[i] - a[i - 1] == 2) {
                ans++;
            }
        }
        int mis_end = n - a[x - 1];
        int mis_front = a[0] - 1;
        
        if (mis_end + mis_front == 1) ans++;
        cout<<ans<<endl; 
    }
}