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
    // ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, r; cin>>n>>r; 
        int sum = 0, rst = 0; 
        vi a(n);

        for (int i = 0; i < n; i++) {
            cin>>a[i];
            if (a[i] % 2) sum += a[i] - 1, rst++;
            else sum += a[i];
        }
        int ans = sum; 
        int left = 2 * r - sum; 
        bool add = false; 
        if (left >= 2 * rst) ans += rst;
        else {
            while (left > 1 && rst > 1 && left < 2 * rst) {
                add = true;
                left -= 2;
                rst -= 2;
            }
        }
        
        if (add) ans += rst; 
        cout<<ans<<endl; 
    }
}