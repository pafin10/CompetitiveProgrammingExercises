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
const string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int32_t main() {
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin>>s; 
    int ans = 0, i = 0; 
    vi pos; 

    while (i < 26) {
        for (int j = 0; j < 26; j++) {
            if (alph[i] == s[j]) {
                pos.pb(j);
                i++;
                break; 
            }   
        }
    }
    for (int i = 1; i < 26; i++) ans += abs(pos[i] - pos[i-1]);
    cout<<ans<<endl; 

}