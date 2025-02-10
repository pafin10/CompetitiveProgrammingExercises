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
#include <deque>


using namespace std;
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
//#define int long long
const int MAX_N = 100'005;

int32_t main() {
    // ifstream cin("Salyg1nAndTheMEXGame.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n;
        set<int> se;

        for (int i = 0; i < n; i++) {
            int j; cin>>j; 
            se.insert(j);
        }
        int cnt = 0, val = 1, lastVal = 0; 
        bool next = false; 
        int maxi = 0;
        int in; 

        while (cnt < 2 * n + 1 && val) {
            val = 0;

            if (lastVal) val = min(in, lastVal);
            else while (se.find(val) != se.end()) {
                ++val;
            }
            maxi = max(maxi, val);
            cout<<val<<endl;
            cout.flush();
            cin>>in;
            if (!val) {
                while (in != -1) cin>>in;
            }
            if (in == -1) {
                next = true;
                break;
            };
            lastVal = val;
            se.erase(in);
            cnt++;
        }
        if (next) continue;
    }
}