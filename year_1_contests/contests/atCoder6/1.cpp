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
    //ifstream cin ("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t=1;//cin>>t; 
    while(t--) {
        int n, m; cin>>n>>m; 
        vi a(m);
        int ans = 0; 
        it(i,0,m) {cin>>a[i]; if (a[i] == 1 || a[i] == n || n == m+1 || n == m) ans = -1; }
        if (ans == -1) {cout<<ans<<endl; continue;}
        
        sort(all(a));
        vi perm; 
        int j = 1, insert = -1;
        it(i,0,m) {
            while (j < a[i]) {
                if (insert != -1) perm.pb(insert);
                else perm.pb(j);
                j++;
                insert = j;
            }
            perm.pb(j+1);
            j++;
        }
        if (insert != -1) perm.pb(insert);
        int k = perm.size();
        int maxi = -1; 
        it(i,0,k) if (perm[i] > maxi) maxi = perm[i];
        if (k < n) {
            it(i, maxi+1 , n+1) perm.pb(i);
        }
        vout(perm);
        cout<<endl;  
    }
}