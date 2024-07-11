#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>

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
using namespace std;
//#define int long long

bool isBeautiful(vi& a, int n);

bool isBeautiful(vi& a, int n, vector<bool>& beautiful) {
    sort(all(a));

    int first = a[0];
    int second = a[1];
    
    it(i,0,n) {
        if ((a[i] % first) == 0) beautiful[i] = true;     
    }
    bool start = true, valid = true;
    int div = -1;
    it(i,0,n) {
        if (!beautiful[i] && start) {div = a[i]; start = false; }
        else if (!beautiful[i]) {
            if ((a[i] % div) != 0) {
                valid = false; 
                break; 
            }
        }
    }

    return valid;
}

int32_t main() {
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vi a(n);
        vector<bool> beautiful(n, false); 
        it(i,0,n) cin>>a[i];

        if (isBeautiful(a, n, beautiful)) 
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }

    return 0;
}
