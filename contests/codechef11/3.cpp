#include <iostream>
#include <vector>
#include <climits> 
#include <fstream>
#include <algorithm>

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
    //ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; 
    while(t--) {
        ll n, k; 
        cin >> n >> k;
        vll a(n);
        ll minOut1 = LLONG_MAX, maxOut1 = LLONG_MIN;
        it(i, 0, n) {
            int j; 
            cin >> j; 
            a[i] = j % k;
        }
        sort(all(a));
        ll ans = a[n-1] - a[0];
        ll maxi = a[0]+k;
        it(i,1,n) {
            ans = min(ans, maxi-a[i]);
            a[i] += k;
            maxi = a[i];
        }
        cout<<ans<<endl; 
        
    }
    return 0;
}
