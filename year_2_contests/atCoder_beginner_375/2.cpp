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
#include <array>
#include <iomanip>


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
#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n; 

    pii curr = {0, 0};
    double total = 0.0, dist = 0.0; 

    for (int i = 0; i < n; i++) {
        int x, y; cin>>x>>y; 
        dist = sqrt(double((curr.ff - x)) * (curr.ff - x) + 
        (curr.ss - y) * (curr.ss - y));
        total += dist; 
        curr = {x, y};
    }
    dist = sqrt(curr.ff * curr.ff + curr.ss * curr.ss);
    total += dist;

    constexpr auto max_precision{numeric_limits<long double>::digits10 + 1};
    cout<<setprecision(max_precision)<<total<<endl; 

}