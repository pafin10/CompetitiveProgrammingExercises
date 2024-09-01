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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t=1;//cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m; 
        vi a(m);
        it(i,0,m) cin>>a[i];
        vi nutrientSum(m);
        it (k,0,n) {
            it (i,0,m) {
                int j; cin>>j; 
                nutrientSum[i] += j; 
            }
        }
        string ans = "Yes";
        it(i,0,m) if (nutrientSum[i] < a[i]) {ans = "No"; break;}
        cout<<ans<<endl; 
    }
}