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
    ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; 
        vi a(n);
        vector<pair<int, int>> p(n); // element from a, original position
        it(i,0,n) {cin>>a[i]; p[i].ff = a[i]; p[i].ss = i;}
        sort(all(p));
        

        vi distribution(n,1);
        int i = 1, coins = 0;
        bool keep = true; 
        while (keep) {
            keep = false; 
            distribution[n-1] = p[n-1].ff * (p[n-1].ff + i);
            coins = distribution[n-1];
            itb(i, n-2, 0) {
                distribution[i] = distribution[n-1] / p[i].ff;
                coins += distribution[i];
                if (coins > distribution[i] * p[i].ff) keep = true;
            }
        }
        vout(distribution);
        cout<<endl; 


    }
}