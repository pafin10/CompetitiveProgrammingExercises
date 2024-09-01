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
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n; 
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    int j = 0; 
    int ans = 0; 
    int sub = 0; 

    if (n == 1) ans = 1; 
    else {
        while (j < n - 1) {
            int i = j; 
            int d = a[j+1] - a[j];

            while (j < n - 1 && a[j+1] - a[j] == d) j++;
            int l = j - i + 1;
            ans += l * (l+1) / 2;
            if (i) sub ++;
        }
    }
    cout<<ans - sub<<endl; 

    
}