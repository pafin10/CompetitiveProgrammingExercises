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
#define rev(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define INF (ll)1e18

int main(int argc, char const *argv[]) {
    //ifstream cin("5.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        ll n,k,q; cin>>n>>k>>q;
        vll a(k+1,-1), b(k+1,-1);
        a[0] = 0; b[0] = 0;
        it(i,1,k+1) cin>>a[i];
        it(i,1,k+1) cin>>b[i];

        it(i,0,q) {
            ll d; cin>>d;
            ll ans = -1;
            if (d==0) ans=0;
            // bin search
            ll left = 0, right = k; 
            while (left < right) {
                ll mid = left + (right - left) / 2;
                if (a[mid] <= d)
                    left = mid + 1;
                else
                    right = mid;
            }
            if (a[left] >= d) {
                ll j = left-1;
                while(j >= 0 && a[j] == -1) j--;
                if (ans != 0) ans = b[j] + (d-a[j]) * (b[left] - b[j]) / (a[left]-a[j]);
                cout<<ans<<" ";
            }
        }
        cout<<endl;
    }
}