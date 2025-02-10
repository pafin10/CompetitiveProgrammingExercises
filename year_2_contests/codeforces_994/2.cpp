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
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string s; cin>>s; 
        bool both = false, alldots = true;
        int s_cnt = 0, p_cnt = 0; 
        string ans = "YES"; 
        vi perm(n);

        for (int i = 0; i < n; i++) {
            if (s[i] != '.') alldots = false; 
            if (s[i] == 's') {
                perm[i] = s_cnt++;
            }
            else if (s[i] == 'p') {
                perm[i] = s_cnt++;
            }
        }
        int cnt = 1; 
        for (int i = 0; i < n; i++) {
            
        }
        if (alldots || !(s_cnt && p_cnt)) {
            cout<<"YES"<<endl; 
            continue;
        }
        int firstp = -1, lasts = -1;
        for (int i = 0; i < n; i++) {
            if (firstp == -1 && s[i] == 'p') firstp = i; 
            if (s[i] == 's') lasts = i; 

        }
        if (firstp < lasts) ans = "NO";
        if (s[0] == '.' && s[n - 1] == '.') both = true; 
        if (both && !alldots && (s_cnt && p_cnt)) ans = "NO";

        cout<<ans<<endl; 

    }
}