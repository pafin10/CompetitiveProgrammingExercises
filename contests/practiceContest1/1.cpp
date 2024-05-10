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
    //ifstream cin("1.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; //cin>>t; 
    t=1;
    while(t--) {
        int n, q; cin>>n>>q; 
        vll a(n);
        it(i,0,n) cin>>a[i];
        
        it(i,0,q) {
            ll l, r; cin>>l>>r; 
            l--, r--;
            ll out = 0;
            vll sub(a.begin()+l+1, a.begin()+r);
            sort(sub.begin(), sub.end());

            ll ax = 0, ay = 0; 
            if (a[l] * a[r] < 0) {
                ax=sub[0];
                ay = (ax < 0) ? sub[sub.size() - 1] : sub[1];
                out = ax*ay; 
            }
            else {
                ax=sub[sub.size()-1], ay=sub[sub.size()-2];
                out = max(ax*ay, (sub[0]*sub[1]));
            }
            cout<<(ll)a[l]*a[r]*out<<endl; 
        }

    }
}