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
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, d, k; cin>>n>>d>>k; 
        vi starts, ends; 

        for (int i = 0; i < k; i++) {
            int l, r; 
            cin>>l>>r;
            l--; r--;

            starts.pb(l);
            ends.pb(r);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        auto startPtr = starts.begin(), endPtr = ends.begin();
        int active = 0; 
        int b = 0, m = 0;
        int maxi = 0, mini = k + 1;

        vi st; 
        for (int i = 0; i < n - d + 1; i++) {
            while (startPtr != starts.end() && *startPtr == i) {
                st.pb(starts[*startPtr]);
                active++;
                startPtr++;
            }
            while (i > 0 && i < n && endPtr != ends.end() && *endPtr == i + 1) {
                active--;
                endPtr++;
            }
            
            auto tmpPtr = st.begin();
            while (tmpPtr != st.end() && *tmpPtr + d < i - 1) {
                active--;
                tmpPtr = st.erase(tmpPtr);
            }
            
           
            if (active > maxi) {
                b = i + 1;
                maxi = active; 
            }
            if (active < mini) {
                m = i + 1;
                mini = active;
            }
        }
        cout<<b<<" "<<m<<endl; 
    }
}