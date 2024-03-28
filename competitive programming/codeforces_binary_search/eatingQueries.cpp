#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)
#define pb push_back

int main(int argc, char const *argv[]) {
    // NEEDS EFFICIENCY IMPROVEMENTS

    // ifstream cin("eatingQueries.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t; 
    while(t--) {
        ll n, q; cin>>n>>q;
        vector<ll> a(n);

        it(i, n) cin>>a[i];
        sort(a.begin(), a.end(), greater<int>());
        vector<ll> candies(n+1);
        ll sm = 0;
        candies[0] = 0;
        it(i, n) {
            sm += a[i];
            candies[i+1] = sm;
        }

        while(q--) {
            ll x; cin>>x; 
            if (x > candies[n]) {
                cout<<-1<<endl; 
                continue;
            }
            ll left = 0, right = candies.size() - 1;

            while (left < right) {
                ll mid = left + (right - left) / 2;
                if (candies[mid] < x) {
                    left = mid +1;
                }
                else {
                    right = mid;
                }
            }
            cout<<left<<endl; 
        }
    }

    return 0;
}
