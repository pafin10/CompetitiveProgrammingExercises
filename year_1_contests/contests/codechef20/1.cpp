#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_map>
#include <cassert>


using namespace std;
#define NDEBUG
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define itb(i, start, n) for (int i = start; i >= n; --i)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
//#define int long long
const int MAX_N = 100'005;

int32_t main() {
    //ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 
        string s,t; cin>>s>>t;
        int zeroS = 0, zeroT = 0;

        int diffCnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) diffCnt++;
            if (s[i] == '0') zeroS++;
            if (t[i] == '0') zeroT++;
        }
        if (zeroS != zeroT) {
            cout<<"NO"<<endl; 
            continue;
        }
        if (n == 2) {
            if (s != t && k % 2 == 1) cout<<"YES"<<endl; 
            else if (s==t && k % 2 == 0) cout<<"YES"<<endl; 
            else if (zeroT == n || zeroT == 0) cout<<"YES"<<endl; 
            else cout<<"NO"<<endl; 
            continue;
        }
        if (k * 2 < diffCnt) {
            cout<<"NO"<<endl; 
        }
        else cout<<"YES"<<endl; 
    }
}