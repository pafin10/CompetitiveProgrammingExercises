#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)
#define pb push_back

bool comparePositionsInA(const vector<pair<ll, ll>>& a, ll i, ll j) {
    return a[i].second < a[j].second;
}

int main(int argc, char const *argv[]) {

    // ifstream cin("collectingGame.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   

    int t; cin>>t; 
    while(t--) {
        ll n; cin>>n;
        vector<pair<ll, ll>> a(n);
        // second entry is the original position
        it(i, n) {
            cin>>a[i].first;
            a[i].second = i; 
        }

        sort(a.begin(), a.end());
        vector<ll> cumulVec(n);
        vector<ll> out(n);
        cumulVec[0] = a[0].first;
        ll k = 1; 
        while(k < n && a[k].first <= cumulVec[0]) {
            cumulVec[0] += a[k].first;
            k++;
        }
        for (int i = 1; i < n; i++) {
            cumulVec[i] = cumulVec[i-1] + a[i].first;
        }
        
        it(i, n) {
            out[i] = i;
            ll j = i+1; 
            // probably here binary search, for now naive
            while(j < n && cumulVec[i] >= a[j].first) {
                out[i]++;
                j++;
            }
        }
        vector<ll> ans(n);
        it (i, n) {
            ans[a[i].second] = out[i];
        }

        it (i, n) cout<<ans[i]<<" ";
        cout<<endl;        
    
    }

    return 0;
}
