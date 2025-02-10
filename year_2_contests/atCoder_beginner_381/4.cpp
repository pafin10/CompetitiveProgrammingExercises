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
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t = 1; //cin>>t; 

    while(t--) {
        int n; cin>>n;
        vi v(n);
        for (auto& i : v) cin>>i; 

        map<int, int> m;

        int cnt = 0, ans = 0; 
        for (int i = 0; i < n - 1; i++) {
            if (v[i] == v[i + 1]) {
                if (i < n - 2 && v[i + 2] == v[i]) {
                    if (i < n - 3) {
                        if ((i < n - 3 && v[i + 3] != v[i]) || i == n - 3) {
                            ans = max(ans, cnt + 2);
                            m.clear();
                            cnt = 0;
                            continue;
                        }
                    }
                }
                else if (!m[v[i]]) {
                    m[v[i]]++;
                    i++;
                    cnt += 2;
                }
                else {
                    ans = max(ans, cnt);
                    cnt = 0;
                    m.clear();
                } 
            }
            else {
                cnt = 0; 
                m.clear();
            }
            ans = max(ans, cnt);
        }
        
        cout<<ans<<endl; 
    }
}