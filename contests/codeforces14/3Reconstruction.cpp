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
    //ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int n, k; cin>>n>>k;
        vll a(n);
        it(i,0,n) cin>>a[i];
        vector<vll> dp(n+1, vll(k+1, INF));
        dp[0][0] = 0;

        it(i,0,n) {
            it(j,0,k+1) {
                ll mn = INF; 
                it(d,0,min(n-i, k-j+1)) {
                    mn = min(mn, a[i+d]);
                    dp[i+d+1][j+d] = min(dp[i+d+1][j+d], dp[i][j] + (d+1) * mn);
                }
            }
        }
        cout<<*min_element(dp[n].begin(), dp[n].end())<<endl;
    }
}