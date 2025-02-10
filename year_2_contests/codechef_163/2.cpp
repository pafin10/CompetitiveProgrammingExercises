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
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 
        vi a(n), pos, neg;

        for (auto& i: a) cin>>i; 
        for (auto i: a) {
            if (i > 0) pos.pb(i);
            else if (i < 0) neg.pb(i);
        }

        int pos_max = 0, pos_min = 0;
        int neg_min = 0, neg_max = 0; 
        for (int i = 0; i < sz(pos); i++) {
            pos_max += int(ceil(double(pos[i]) / k));
            pos_min += pos[i] / k; 
        }
        for (int i = 0; i < sz(neg); i++) {
            neg_min += int(floor(double(neg[i]) / k));
            neg_max += neg[i] / k; 
        }
        if (abs(neg_max) <= pos_min && pos_min <= abs(neg_min)
        || pos_min <= abs(neg_max) && abs(neg_max) <= pos_max) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl;
    }
}