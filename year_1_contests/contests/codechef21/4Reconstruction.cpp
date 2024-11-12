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
    //ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n,x,k; cin>>n>>x>>k; 
        vi h(n);
        map<int ,int> m; 

        for (int i = 0; i < n; i++) {
            cin>>h[i];
            m[h[i]]++;
        }

        // CASE 1: USE SPELL RIGHT AWAY
        int ans = 0;
        sort(h.begin(), h.end());
        vi tmp = h;
        tmp.resize(distance(tmp.begin(), unique(tmp.begin(), tmp.end())));

        auto it = lower_bound(tmp.begin(), tmp.end(), x * k) - tmp.begin();
        ans = it; 
        
        // CASE 2: USE SPELL LATER
        // first, find starting point
        int ind = -1;
        for (int i = n-1; i >= 0; i--) {
            if (h[i] < x) {
                ind = i; 
                break;
            }
        }

        unordered_map<int, int> visited, visited1;
        int cnt = 0;
        // count elements that can be defeated before spell
        for (int i = ind; i >= 0; i--) {
            if (!visited[h[i]] && m[h[i]]) {
                visited[h[i]] = 1;
                cnt++;
                m[h[i]]--;
                if (!m[h[i]]) m.erase(h[i]);
            }
        }

        // own array with duplicate elements
        vi tmp2;
        for (int i = 0; i < n; i++) {
            if (m[h[i]] && !visited1[h[i]]) {
                tmp2.pb(h[i]);
                visited1[h[i]] = 1;
            }
        }

        int maxi = 0; 
        // find max num of elements that can still be defeated after the spell
        if (cnt) {
            for (int i = 0; i < sz(tmp2); i++) {
                if (visited[tmp2[i]]) {
                    auto it = lower_bound(tmp2.begin(), tmp2.end(), k * tmp2[i]) 
                    - tmp2.begin(); // index 
                    maxi = max(maxi, it - i); // how many monsters can we still kill if we use the spell here
                }
            }
        }

        cout<<max(ans, cnt+maxi)<<endl; 
    }
}