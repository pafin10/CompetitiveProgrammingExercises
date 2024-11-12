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
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while (t--) {
        int n, x;
        cin >> n >> x; // Number of models and maximum cars per customer

        vector<int> a(n); // Cars of each model
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int total_customers = 0;
        // Iterate over each model and calculate required customers
        for (int i = 0; i < n; i++) {
            total_customers += (a[i] + x - 1) / x; // This is ceil(a[i] / x)
        }
        
        cout << total_customers << "\n"; // Output result for this test case
        }
}