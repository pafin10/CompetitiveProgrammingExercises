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
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while (t--) {
        int n; 
        cin >> n;
        vi a(n);

        int ans = 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (n == 1) {
            cout << 1 << endl;
            cout << a[0] << endl;
            continue;
        }

        vi operations;
        bool done = false, zero = false;
        for (int cnt = 0; cnt < 40 && !done; ++cnt) {
            sort(a.rbegin(), a.rend()); 
            if (ans == -1) break;
            int diffs = 0;
            for (int i = 0; i < n; ++i) {
                if (i && a[i] != a[i-1]) diffs++;
                if (a[i] == 0) zero = true;
                if (i && abs(a[i] - a[i-1]) % 2 == 1) ans = -1;
            }
            
            int x = a[1]; 
            if (diffs == 1 && zero) x = max(a[0], a[n-1]) / 2;
            
            operations.push_back(x);
            for (int i = 0; i < n; ++i) {
                a[i] = abs(a[i] - x);
            }
            
            done = all_of(a.begin(), a.end(), [](int val) { return val == 0; });
        }

        if (!done || ans == -1) {
            cout << -1 << endl;
        } else {
            cout << sz(operations) << endl;
            for (int op : operations) {
                cout << op << " ";
            }
            cout << endl;
        } 
    }
}