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
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n);    
        map<int, int> m; 

        for (auto& i: a) {
            cin>>i; 
            m[i]++;
        }

        vector<int> b; 
        b.push_back(a[0]);
        map<int, bool> in_b; 
        in_b[a[0]] = 1; 

        int cnt; 
        for (int i = 1; i <= n; i++) {
            if (!m.count(i)) {
                cnt = i; 
                break; 
            }
        }

        for (int i = 1; i < n - 1; i++) {
            if (in_b[a[i]]) {
                if (!in_b.count(a[i + 1])) {
                    b.push_back(a[i + 1]);
                    in_b[a[i + 1]] = 1;
                }
                else {
                    b.push_back(cnt); 
                    in_b[cnt] = 1; 
                    cnt++;
                    while (m.count(cnt)) cnt++;
                }
            }
            else {
                b.push_back(a[i]);
                in_b[a[i]] = 1;
            }
        }
        if (n > 1) b.push_back(a[n - 1]);
        for (auto& i: b) cout<<i<<" ";
        cout<<endl; 
    }
}