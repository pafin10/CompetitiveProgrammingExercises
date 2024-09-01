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
    ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n);
        it(i,0,n) cin>>a[i];
        int runSum = 0, cnt = 0, maxi = -1;
        bool even = false; 
        it(i,0,n) {
            if (a[i] % 2 == 0) even = true; 
            if ((runSum + a[i]) % 2 == 0) runSum += a[i], cnt++;
            else runSum = a[i], cnt = 1;
            if (cnt > maxi) maxi = cnt; 
        }
        cout<<maxi<<endl; 
    }
}