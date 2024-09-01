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
    //ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n; 
    vi a(n);
    for (int i = 0; i< n; i++) {
        cin>>a[i];
    }

    int ans = 0, defCnt = 0; 
    int i; 
    
    for (i = 0; i < n - 1; i++) {
        int tmp1 = a[i];
        int tmp2 = 0; 
        bool nextEven = (defCnt % 2 == 1);

        if (nextEven) {
            tmp1 = 2 * a[i] + a[i+1];
            tmp2 = 2 * a[i+1];
        }
            
        if (tmp1 > tmp2) {
            ans += tmp1;
            if (nextEven) {
                defCnt += 2;
                i++;
            }
            else defCnt++;
        }     
        else {
            ans += tmp2; 
            if (nextEven) {
                i++;
            }
            defCnt++;
        }
    }

    if (n % 2 == 0) {
        bool nextEven = (defCnt % 2 == 1);
        if (nextEven) {
            ans += 2 * a[n-1];
        }
    }
    cout<<ans<<endl; 
}