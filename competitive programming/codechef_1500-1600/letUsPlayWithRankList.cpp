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
//#define int long long
const int MAX_N = 100'005;

int main(int argc, char const *argv[]) {
    //ifstream cin("letUsPlayWithRankList.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        ll n,s; cin>>n>>s; 
        ll limit = 0; 
        for (ll i = 1; i <= n; i++) {
            ll mini = i * (i+1) / 2 + (n-i);
            ll maxi = i * (i+1) / 2 + (n-i) * i;
            if (s >= mini && s <= maxi) limit = i;
        }
        cout<<n-limit<<endl; 
    }
}