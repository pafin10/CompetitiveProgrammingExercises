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
#include <bitset>
#include <numeric>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

int main(int argc, char const *argv[]) {
    //ifstream cin("4.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        ll n ; cin>>n; 
        vi a(n);
        it(i,0,n) {cin>>a[i];a[i]%=2;}
        ll ans = n*(n+1)/2;

        ll tmp = 0, maxi = 0;
        it(i,0,n) {
            if (a[i] == 0) {
                ans -= tmp*(tmp+1)/2;
                maxi = max(tmp, maxi);
                tmp = 0;
            }
            else tmp++;
        }
        ans -= tmp*(tmp+1)/2;
        maxi = max(tmp, maxi);
        ans += maxi*(maxi+1)/2;

        // left and right of changed element, subarrays still dont have even el, so subtract
        if (maxi%2==0) {
            ans -= (maxi/2) * (maxi/2+1) /2;
            ans -= (maxi/2) * (maxi/2-1) /2;
        }
        else ans -= 2*(maxi/2) * (maxi/2+1) /2;
        cout<<ans<<endl; 
    }
}