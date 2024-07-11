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
#define int long long
const int MAX_N = 100'005;

int32_t main() {
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi x(n), p(n);
        
        it(i,0,n) cin>>x[i];
        it(i,0,n) cin>>p[i];
        int ans = -1;
        int rightStop = 0, leftStop = n; 
        // >>
        it(i,0,n) {
            if (i == n -1) ans = 1;
            else if (x[i] + p[i] >= x[i+1]) continue;
            else {
                rightStop = i; 
                it(j,i+1,n) {
                    if (j == n-1) ans = 1;
                    else if (x[j] + p[j] >= x[j+1]) continue;
                    else break;
                }
                break;
            }
        }

        // << 
        itb(i,n-1,0) {
            if (i == 0) ans = 1;
            else if (x[i] - p[i] <= x[i-1]) continue;
            else {
                leftStop = i; 
                itb(j, i-1, 0) {
                    if (j == 0) ans = 1;
                    else if (x[j] - p[j] <= x[j-1]) continue;
                    else break; 
                }
                break;
            }
        }
        if (rightStop >= leftStop || rightStop +1 == leftStop) ans = 1;

        // < >
        it(i,0,n) {
            if (i == n-1) ans = 1;
            else if (x[i+1] - p[i+1] <= x[i]) continue;
            else {
                it(j, i+1, n) {
                    if (j == n-1) ans = 1;
                    else if (x[j] + p[j] >= x[j+1]) continue;
                    else break; 
                }
                break; 
            }
        }

        if (ans==1) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl; 
    }
}