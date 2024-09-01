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
    ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string s; cin>>s;
        int ones = 0, zeros = 0;
        it(i,0,n) s[i] == '0' ? zeros++ : ones++;
        vi oneCnt(n), zeroCnt(n);
        s[0] == '1' ? (oneCnt[0] = 1, zeroCnt[0] = 0) : (oneCnt[0] = 0, zeroCnt[0] = 1);
        it(i,1,n) {
            if (s[i] == '1') {
                oneCnt[i] = oneCnt[i-1]+ 1;
                zeroCnt[i] = zeroCnt[i-1];
            }
            else {
                zeroCnt[i] = zeroCnt[i-1]+ 1;
                oneCnt[i] = oneCnt[i-1];
            }
        }

        int ans = 0;
        it(i,0,n) {
            if (zeroCnt[i] == oneCnt[i]) ans += 2;
            else ans++;
            it(j,i+1, n) {
                if ((zeroCnt[j] - zeroCnt[i]) == (oneCnt[j] - oneCnt[i])) ans += 2;
                else ans++;
            }
        }
            

        cout<<ans<<endl; 

    }
}