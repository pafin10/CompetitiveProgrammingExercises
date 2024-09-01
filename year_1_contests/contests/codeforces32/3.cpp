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
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        map<char, int> m;
        for (int i = 0; i < n; i++) {
            char e; cin>>e;
            m[e]++;
        }
        vector<char> ans; 
        while (!m.empty()) {
            vector<char> to_erase; 

            for (auto& p : m) {
                ans.pb(p.ff);
                p.ss--;

                if (p.ss == 0) to_erase.pb(p.ff);
            }

            for (auto& er : to_erase) m.erase(er);
        }
        string out(ans.begin(), ans.end());
        cout<<out<<endl; 




    }
}