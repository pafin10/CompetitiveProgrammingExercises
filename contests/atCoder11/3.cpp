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
#define int long long
const int MAX_N = 100'005;

int32_t main() {
    ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int sx, sy; cin>>sx>>sy; 
    int tx, ty; cin>>tx>>ty;
    sx -= ((sy - sx) % 2 + 2) % 2;
    tx -= ((ty - tx) % 2 + 2) % 2;


    tx -= sx; 
    ty -= sy;
    ty = abs(ty);
    tx = abs(tx);

    int ans = ty + (max(0LL, (tx - ty) / 2) );
    cout<<ans<<endl; 
    
}