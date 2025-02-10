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
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string s; cin>>s; 
        vi k(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') k[i] = 1;
            else k[i] = 2;
        }

        int ans = 0; 
        while (find(k.begin(), k.end(), 1) != k.end() && 
        find(k.begin(), k.end(), 2) != k.end()) {
            bool s = true; 
            int last = 0;

            for (int i = 0; i < k.size(); i++) {
                if (s) {
                    if (k[i]) {
                        last = k[i];
                        k[i] = 0;
                        s = false; 
                    }
                }
                else {
                    if (k[i] && k[i] != last) {
                        last = k[i];
                        k[i] = 0; 
                    }
                }
            }
            ans++;
            k.erase(remove(k.begin(), k.end(), 0), k.end());
        }
        ans += max(count(k.begin(), k.end(), 1), count(k.begin(), k.end(), 2));
        cout<<ans<<endl; 
    }
}