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
const int MAX_N = 2 * 10 * 100'000;
const int INF = 1E9;


int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi b(n);
        for (int i = 0; i < n; i++) cin>>b[i];

        int k = 10; // fix maximum
        vi a(n);
        a[0] = b[0] + k; 

        int prefSum = a[0]; 
        for (int i = 1; i < n; i++) {
            a[i] = b[i] - prefSum + k;
            prefSum += a[i];
        }

        int maxi = -INF; 
        for (auto& i: a) {
            maxi = max(i, maxi);
        }
        int diff = 0;
        if (maxi > MAX_N) diff = maxi - MAX_N + 1;
        for (auto& i: a) {
            cout<<i - diff<<" "; 
        }
        cout<<endl; 
    }
}