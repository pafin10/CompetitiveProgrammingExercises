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
        int n, k; cin>>n>>k; 
        vi a(n);

        for (auto& i : a) cin>>i;

        sort(a.rbegin(), a.rend());
        int ans = 0;
        int A = 0, B = 0;

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                A += a[i];
            } else {
                B += a[i];
            } 
        }
        

        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                int increase = min(a[i-1] - a[i], k);
                a[i] += increase;
                B += increase;
                k -= increase;
            }
        }
        cout<<max(0LL, A-B)<<endl; 
    }
}