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
    //ifstream cin("change-making.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t =1; //cin>>t; 
    while(t--) {
        // ISSUE IS OVERFLOW, NUMBERS GET WAY TOO BIG EVEN FOR LL, THINK ABOUT ALTERNATIVE
        ll n, s; cin>>n>>s;
        vll dp(s+1, -1); ll last = 1;
        dp[0] = 0, dp[1] = 1;
        vll coins; coins.pb(1);
        it(i,0,n) {
            ll j; cin>>j;
            coins.pb(last * j);
            dp[last * j] = 1;
            last *= j;
        }
        it(i,1,s) {
            if (dp[i] != 0) {
                it(j,0,coins.size()) {
                    if (i+coins[j]<=s) {
                        dp[i+coins[j]] = dp[i+coins[j]] != -1 ? 
                        min(dp[i+coins[j]], dp[i]+1) : dp[i]+1;
                    }
                }
            }
        }
        cout<<dp[s]<<endl; 
       
    }
}