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
    // ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n);
        int ans = 0; 
        for (auto& i : a) cin>>i; 

        bool allz = true, anyz = false; 
        for (int i = 0; i < n; i++) {
            if (a[i]) allz = false; 
            if (!a[i]) anyz = true; 
        }

        if (anyz && !allz) {
            vi b; 
            int st = 0, end = 0; 
            for (int i = 0; i < n; i++) {
                if (a[i]) {
                    st = i; 
                    break; 
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                if (a[i]) {
                    end = i; 
                    break; 
                }
            }
            for (int i = st + 1; i < end; i++) {
                if (!a[i]) {
                    ans = 2;
                }
            }
            if (ans != 2) ans = 1; 
        }
        else if (!anyz) ans = 1; 
        cout<<ans<<endl; 
        
    }
}