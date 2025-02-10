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
        int k; cin>>k; 
        map<int, int> m; 

        for (int i = 0; i < k; i++) {
            int j; cin>>j; 
            m[j]++;
        }
        int nm = k - 2;
        pii ans = {-1, -1};
        for (int i = 0; i * i <= nm; i++) {
            if (m[i]) {
                int mult = nm / i;
                if (i * mult == nm && m[mult]) {
                    ans = {i, mult};
                    break;
                }
            }
        }
        cout<<ans.ff<<" "<<ans.ss<<endl; 
    }
}