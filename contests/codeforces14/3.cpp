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
#define rev(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define INF (ll)1e18


int main(int argc, char const *argv[]) {
    // explanation from tutorial in .txt
    //ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int n, k; cin>>n>>k; 
        vll a(n);
        ll sum = 0;
        it(i,0,n) cin>>a[i]; 
        if (n==1) {cout<<a[0]<<endl; continue;}
        vector<vll> dp(n+1, vll(k+1, INF));
        // first dimension: #positions already considered, second dimension: #operations so far

        dp[0][0] = 0;
        it(i,0,n) {
            it(j,0,k+1) {
                ll mn = INF;
                it(d,0,min(n-i, k-j+1)) {
                    mn = min(mn, a[i+d]); // min el up to current pos in original vector
                    dp[i+d+1][j+d] = min(dp[i+d+1][j+d], dp[i][j] + (d+1) * mn);
                }
            }
        }
        cout<<*min_element(dp[n].begin(), dp[n].end())<<endl;
        
    }
}