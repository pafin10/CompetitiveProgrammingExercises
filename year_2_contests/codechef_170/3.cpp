#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
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
#include <deque>


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
#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        int ans = n * n; 

        vector<int> a(n);
        int sum = 0;

        for (auto& i: a) {
            cin>>i;
            sum += i; 
        }
        sort(a.begin(), a.end());

        ans = max(ans, sum);
        for (int i = 0; i < n; i++) {
            sum -= a[i];
            ans = max(ans, sum + (i + 1) * (i + 1));
        }
        
        cout<<ans<<endl; 
    }
}