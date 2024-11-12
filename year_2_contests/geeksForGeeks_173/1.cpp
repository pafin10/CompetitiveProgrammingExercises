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
#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t = 1;//cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n);
        int x; cin>>x; 
        for (auto& i : a) cin>>i; 
        

        long long ans = -1; 
        sort(a.rbegin(), a.rend());

        if ((1 << x) > a[0]) {
            cout<<ans<<endl; 
        }
        else {
            long long bit = a[0] & (1<<x);
            long long k = a[0], l = -1;

            for (int i = 1; i < n; i++) {
                if ((a[i] & (1 << x)) != bit) {
                    l = a[i];
                    break;
                }
            }

            if (l == -1) {
                cout<<-1<<endl; 
            }
            else {
                cout<<k + l<<endl; 
            }
        }
    }
}