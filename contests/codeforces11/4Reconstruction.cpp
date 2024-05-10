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


using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

const int N = 1e5 + 10;
vi dp;
bool ans[N]; 
int t; 

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //ifstream cin("4.txt");
     dp.pb(1);
    it(i,0,dp.size()) {
        if (dp[i]*10 >= N) break; 
        dp.pb(10*dp[i]);
        dp.pb(10*dp[i]+1);
    }

    ans[1] = 1;
    
    it (i,2,N) {
        for (auto bd: dp) {
            if (i%bd==0) ans[i] |= (ans[i/bd]);
        }
    }

    cin>>t; 
    while(t--) {
        int n; cin>>n;
        cout<<(ans[n] ? "YES" : "NO")<<endl; 
    }
}