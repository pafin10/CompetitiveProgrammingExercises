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
        int n,m; cin>>n>>m; 
        vi a(n), b(m);
        it(i,0,n) cin>>a[i];
        it(i,0,m) cin>>b[i];

        sort(all(a)); 
        sort(all(b));
        int j = 0;
        int cnt = 0, i = 0; string ans = "No";
        while (i < n && j < m) { 
            while (i < n && a[i] < b[j] && cnt < 3) {cnt++; i++;}
            if (cnt >= 2) {ans = "Yes"; break;}
            cnt = 0;
            j++;
        }
        if (n > 1 && a[n-2] > b[m-1]) ans = "Yes";
        cout<<ans<<endl; 
    }
}