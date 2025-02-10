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
#include <unordered_set>
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
unordered_set<int> us;


int32_t main() {
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            int j; cin>>j; 
            a[i] = j; 
            us.insert(j);
        }

        map<int, int> m, cnts;
        for (int i = 0; i < n; i++) {
            m[a[i]] = k - a[i];
            cnts[a[i]]++;
        }

        int ans = 0; 
        int cnt = 0; 
        for (int i = 0; i < n; i++) {
            if (us.find(m[a[i]]) != us.end()) {
                cnt++;
                cnts[m[a[i]]]--;
                if (cnts[m[a[i]]] == 0) us.erase(m[a[i]]);
            }
        }
        us.clear();
        cout<<cnt / 2<<endl; 
    }
}