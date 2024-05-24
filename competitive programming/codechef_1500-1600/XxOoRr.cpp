#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>


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
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
//#define int long long
const int MAX_N = 100'005;

int main(int argc, char const *argv[]) {
    //ifstream cin("XxOoRr.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n,k; cin>>n>>k; 
        vi a(n);
        it(i,0,n) cin>>a[i];
        vi bitCounts(31,0);

        sort(all(a));
        it(i,0,n) {
            int j = 31;
            while(j--) {
                bitCounts[j] += a[i] & 1;
                a[i] >>= 1;
            } 
        }
        int ans = 0;
        it(i,0,31) ans += (int)ceil(bitCounts[i]/(double)k);
        cout<<ans<<endl; 
    }
}