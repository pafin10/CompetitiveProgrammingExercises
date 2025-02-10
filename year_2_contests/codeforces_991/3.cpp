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
#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;

int32_t main() {
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        string s; cin>>s;
        int n = s.size(); 

        map<int, int> m; 
        int num = 0; 
        int two_cnt = 0, three_cnt = 0;
        for (int i = 0; i < n; i++) {
            num += s[i] - '0';
            if (s[i] - '0' == 2) two_cnt++;
            if (s[i] - '0' == 3) three_cnt++;
        }
 
        string ans = "NO";
        if (num % 9 == 0) ans = "YES";
        else {
            bool f = false; 
            for (int i = 0; i <= two_cnt; i++) {
                if (f) break; 
                for (int j = 0; j <= three_cnt; j++) {
                    if ((num + (2 * i + 6 * j)) % 9 == 0) {
                        ans = "YES";
                        f = true; 
                        break; 
                    }
                }
            }
        }
        cout<<ans<<endl; 
    }
}