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


using namespace std;
#define NDEBUG
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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t; cin>>s>>t; 
    int n = s.length();
    
    bool found = false;
    
    for (int w = 1; w < n && !found; ++w) {
        for (int c = 0; c < w && !found; ++c) {
            string formed = "";
            for (int i = c; i < n; i += w) {
                formed += s[i];
            }
            if (formed == t) {
                found = true;
                break;
            }
        }
    }
    
    cout << (found ? "Yes" : "No") << endl;

    
}