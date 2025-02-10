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
    
    // NOTES: for any n, k where k != 1 and !(n % 2 && k == 2), we have two cases:
    // even n: just pair adjacent numbers and swap elements at indices s.t. 1->2, 2->1...
    // odd n and k > 2: adjust the first three manually: 1->2, 2->3, 3-> 1
    while(t--) {
        int n, k; cin>>n>>k; 
        if (k == 1 || (n % 2 && k == 2)) {
            cout<<-1<<endl; 
            continue; 
        }

        vi ans(n + 1); ans[0] = 0;
        if (n % 2) {
            ans[1] = 2; 
            ans[2] = 3;
            ans[3] = 1;
            for (int i = 4; i <= n; i++) {
                if (i % 2) ans[i] = i - 1;
                else ans[i] = i + 1;
            }
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (i % 2) ans[i] = i + 1;
                else ans[i] = i - 1;
            }
        }
        for (auto e : ans) if (e) cout<<e<<" ";
        cout<<endl; 
    }
}