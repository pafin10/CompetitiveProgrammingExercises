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
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m; 
        string s, k; 
        cin>>s>>k; 
        if (s[0] != k[0]) {
            cout<<-1<<endl; 
            continue;
        }
        
        if (s == k) {
            cout<<0<<endl; 
            continue;
        }

        if (n < m) swap(s, k); // s is now longer one
        int start = -1; 
        for (int i = 0; i < min(n, m); i++) {
            if (s[i] != k[i]) {
                start = i; 
                break;
            }
        }
        if (start == -1) {
            cout<<1<<endl; 
            continue;
        }

        string s_new = s.substr(start), k_new = k.substr(start);
        if (s_new.rfind(k_new) == (s_new.size() - k_new.size())) 
            cout<<1<<endl; 
        else cout<<2<<endl; 
    }
}