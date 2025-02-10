#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <array>
#include <deque>


using namespace std;
#define NDEBUG
#define ll long long
#define endl "\n"
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
const int INF = 1E9;


int32_t main() {
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, r; cin>>n>>r; 
    vi d(n), a(n);
    pii range1 = {1600, 2799}, range2 = {1200, 2399};
    for (int i = 0; i < n; i++) {
        cin>>d[i];
        cin>>a[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
            if (range1.ff <= r && r <= range1.ss) r += a[i];
        }
        else {
            if (range2.ff <= r && r <= range2.ss) r += a[i];
        } 
    }
    cout<<r<<endl; 

}