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
const int MAX_N = 100'005;

int main(int argc, char const *argv[]) {
    // ifstream cin("exactlyN+1Values.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        if (n==1) {
            cout<<(ll) pow(2,n-1)<<" "<< (ll) pow(2,n-1)<< endl; 
            continue;
        }
        ll minVal = n * (n+1) / 2 + 1, maxVal = 0;
        vll ans;
        ll maxi = pow(2, n-1);
        if (n > 58) maxi = pow(2, n-3);
        it (i,1,n) {maxVal +=  (maxi - i); ans.pb(maxi-i);}
        maxVal += 2*maxi; ans.pb(maxi); ans.pb(maxi);
        
        ll sm = pow(2, n);
        ll diffMin = abs(minVal - sm), diffMax = abs(maxVal - sm);
        if (diffMin < diffMax) {
            ans.clear(); ans.pb(1);
            it (i,1,n+1) ans.pb(i);
            it(i,0,n+1) ans[i] += (diffMin / (n+1)); 
            if (diffMin % (n+1) != 0) ans[n] += (diffMin % (n+1));
        }
        else {
            it(i,0,n+1) ans[i] -= (diffMax / (n+1)); 
            if (diffMax % (n+1) != 0) ans[0] -= (diffMax % (n+1));
        }
        it(i,0,n+1) cout<<ans[i]<<" ";
        cout<<endl; 
    }
}