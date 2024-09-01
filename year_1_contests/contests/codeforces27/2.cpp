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
    int t; cin>>t; 

   while(t--) {
        int n; 
        cin >> n; 
        vi b(n-1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> b[i];
        }
        
        vi a(n, 0);
        a[0] = b[0];

        for (int i = 1; i < n - 1; ++i) {
            a[i] = b[i-1];
            if ((a[i] & b[i]) != b[i]) {
                a[i] = b[i-1] | b[i];
            }
        }
        a[n-1] = b[n-2];

        bool valid = true;
        for (int i = 1; i < n; ++i) {
            if ((a[i-1] & a[i]) != b[i-1]) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << -1 << endl;
        } else {
            vout(a);
            cout << endl;
        }
    }
}