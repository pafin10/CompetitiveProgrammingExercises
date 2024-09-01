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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n;
        vi a(n);
        int even = 0, odd = 0;
        int maxOdd = 0;
        for (int i = 0; i < n; i++) {
            cin>>a[i];
            if (a[i] % 2 == 0) even++;
            else {
                odd++;
                maxOdd = max(maxOdd, a[i]);
            }
        }
        if (odd == n || even == n) {cout<<0<<endl; continue;}
        
        sort(a.begin(), a.end());
        int ans = 0, add = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                if (maxOdd <= a[i]) {
                    add = 1;
                    break; 
                }
                maxOdd += a[i];
            }   
        }
        cout<<even+add<<endl; 
    }
}