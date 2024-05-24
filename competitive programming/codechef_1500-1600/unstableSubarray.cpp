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
#include <stack>


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
//#define int long long
const int MAX_N = 100'005;

int main(int argc, char const *argv[]) {
    //ifstream cin("unstableSubarray.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        ll n; cin>>n; 
        vll a(n);
        bool allSame = true;
        it(i,0,n) {cin>>a[i]; if (i && a[i] != a[i-1]) allSame = false;}
        if (allSame) {cout<<0<<endl; continue;}
        sort(all(a));
        ll ans = 0;
        it(i,0,n) {
            int j = i;
            while(a[j] == a[j+1]) j++;
            ans += j-i;
        }
        ans = n*(n-1)/2-ans; 
        cout<<ans<<endl; 

    }
}