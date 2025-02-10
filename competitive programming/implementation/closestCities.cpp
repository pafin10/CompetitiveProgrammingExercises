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
    // ifstream cin("closestCities.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n);

        for (int i = 0; i < n; i++) cin>>a[i];
        vi d(n), d_back(n);
        d[0] = 0; d[1] = 1;

        int last = a[1] - a[0];
        for (int i = 2; i < n; i++) {
            if (a[i] - a[i - 1] < a[i - 1] - a[i - 2]) d[i] = d[i-1] + 1;
            else d[i] = d[i - 1] + (a[i] - a[i - 1]); 
        }

        d_back[n - 1] = 0; d_back[n - 2] = 1;
        for (int i = n - 3; i >= 0; i--) {
            if (a[i + 1] - a[i] < a[i + 2] - a[i + 1]) d_back[i] = d_back[i + 1] + 1;
            else d_back[i] = d_back[i + 1] + (a[i + 1] - a[i]);
        }

        int m; cin>>m; 
        for (int i = 0; i < m; i++) {
            int x, y; cin>>x>>y; 
            x--; y--;

            if (y > x) cout<< d[y] - d[x] <<endl; 
            else cout<< abs(d_back[y] - d_back[x])<<endl;
        }
    }
}