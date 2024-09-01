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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<string> k(n);
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        cin>>k[i];
        maxi = max(maxi, sz(k[i]));
    }
    vector<vector<char>> ans(maxi);
    int cnt = 0;
    vector<char> l; 
    while (cnt < maxi) {
        int starCnt = 0;
        for (int i = n-1; i >= 0; i--) {
            if (cnt >= sz(k[i])) {
                l.pb('*');
                starCnt++;
            }
            else {
                l.pb(k[i][cnt]);
                starCnt = 0;
            }
        }
        if (starCnt > 0) l.resize(sz(l) - starCnt);
        ans[cnt] = l;
        l.clear();
        cnt++;
    }
    for (auto& e: ans) {
        string z(e.begin(), e.end());
        cout<<z<<endl; 
    }
}