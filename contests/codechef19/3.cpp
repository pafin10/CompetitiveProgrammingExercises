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
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n,k,h; 
        cin>>n>>k>>h;

        int minDiff = ((h + (k-1)) / k);
        if (minDiff > n && n < h) {cout<<0<<endl; continue;}
        int a = n; 
        int ans = a - minDiff;

        ans *= (ans+1);
        ans /= 2;

        if (n >= h) {
            int rest = n - h + 1; 
            ans += rest * (rest+1) / 2;
        }
        itb(i, minDiff-1, 1) {
            int j = (k-1) * i;
            int x = h - j; 
            if (x > n || x <= 0) break; 
            int add = n - x + 1;
            ans += add; 
        }

        cout<<ans<<endl; 
    }
}