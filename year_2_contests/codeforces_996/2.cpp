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
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n), b(n);
        
        for (auto& i: a) cin>>i; 
        for (auto& i: b) cin>>i;

        bool ans = 1;
        int neg = 0, min_up = INF;

        for (int i = 0; i < n; i++) {
            if (a[i] - b[i] < 0) {
                if (!neg) neg = abs(a[i] - b[i]);
                else ans = 0;
            }
            else min_up = min(min_up, a[i] - b[i]);
        }
        if (ans && min_up >= neg) cout<<"YES"<<endl;
        else cout<<"NO"<<endl; 
    }
}