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
        int n, x, k; 
        cin>>n>>x>>k; 
        vi h(n);

        for (int i = 0; i < n; i++) cin>>h[i];
        sort(h.rbegin(), h.rend());
        bool dupl = false;

        for (int i = 0; i < n; i++) {
            if (i && h[i] == h[i-1]) dupl = true; 
        }

        // CASE 1: NO DUPLICATES
        if (!dupl) {
            x *= k; 

            int ind = INF;
            for (int i = 0; i < n; i++) {
                if (x > h[i]) {
                    ind = i; 
                    break;
                }
            }
            if (ind == INF) cout<<0<<endl; 
            else cout<<n - ind<<endl; 
        }
        // CASE 2: DUPLICATES
        else {
            // either we increase x directly and fail at first duplicate
            int x1 = x * k; 
            int ind = INF;
            int ans1 = 0, ans2 = 0; 

            int s = 0; 
            for (int i = 0; i < n; i++) {
                if (!s && x > h[i]) s = i; 
                if (i && h[i] == h[i-1]) {
                    ind = i; 
                    break;
                }
            }
            ans1 = ind - s ;
            
            
            // or we leave x as it is and multiply at first duplicate
            int startInd = 0, endInd = -1;
            bool start = false, kUsed = false; 
            for (int i = 0; i< n; i++) {
                if (start) {
                    if (h[i] == h[i-1]) {
                        if (kUsed) {
                            endInd = i; 
                            break; 
                        }
                        kUsed = true; 
                    }
                }
                if (!start && x > h[i]) {
                    startInd = i; 
                    start = true; 
                }
            }
            if (endInd == -1) ans2 = n - startInd;
            else ans2 = endInd - startInd;
            cout<<max(ans1, ans2)<<endl; 
        }
        
    }
}