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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, a, b; cin>>n>>a>>b; 
        int diff = b-a, ans = 0;

        ans += b * (b+1) / 2;
        if (a < b) {
             if (n < diff) {
                a = b - n; 
                ans -= a * (a+1) /2;
                cout<<ans<<endl; 
            }
            else {
                ans -= a * (a+1) /2;
                n -= max(0LL, diff);
                ans += n * a; 
                cout<<ans<<endl; 
            }
        }
        else {
            ans = n*a;
            cout<<ans<<endl; 
        }
       
    }
}