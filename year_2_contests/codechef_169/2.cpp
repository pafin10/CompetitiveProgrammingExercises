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
        int n, k; cin>>n>>k; 
        vector<int> a(n);

        int first = n, last = 0;
        map<int, int> m;
        
        for (int i = 0; i < n; i++) {
            cin>>a[i]; 
            m[a[i]]++;
            if (a[i] == k) {
                if (first == n) first = i;
                last = i;
            } 
        }

        int k_cnt = m[k];
        int ans = 0; 

        for (auto pair: m) {
            if (pair.second > k_cnt) ans = 1;
        }
        if (!ans) {
            cout<<ans<<endl; 
            continue;
        }
        
        map<int, int> m1, m2; 
        
        pair<int, int> max_cnt = {0, 0};
        ans = 2;

        for (int i = 0; i < n; i++) {
            m1[a[i]]++;
            if (m1[a[i]] >= max_cnt.second) {
                max_cnt = {a[i], m1[a[i]]};
            }
            if (max_cnt.first == k) {
                ans = 1; 
                break;
            }
        }
        max_cnt = {0, 0};
        if (ans != 1) {
            for (int i = n - 1; i >= 0; i--) {
                m2[a[i]]++;
                if (m2[a[i]] >= max_cnt.second) {
                    max_cnt = {a[i], m2[a[i]]};
                }
                if (max_cnt.first == k) {
                    ans = 1; 
                    break;
                }
            }
        }
        
        cout<<ans<<endl; 

    }
}