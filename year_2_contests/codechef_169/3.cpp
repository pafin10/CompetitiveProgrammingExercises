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
#include <bit>


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
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> p(n);

        map<int, int> bit_cnt, idx;
        for (int i = 0; i < n; i++) {
            cin>>p[i];
            idx[p[i]] = i; 
        }

        for (int i = 1; i <= n; i++) {
            int b = 0; 
            int tmp = i; 
            while (tmp) {
                b += tmp & 1;
                tmp >>= 1;
            }
            bit_cnt[i] = b;
        }
        
        bool pos = true;

        for (int i = 0; i < n; i++) {
            int el = p[i];
            if (bit_cnt[el] == bit_cnt[i + 1]) {
                swap(p[i], p[idx[i + 1]]);
            }
            else pos = false; 
        }
        if (pos) cout<<"Yes"<<endl; 
        else cout<<"No"<<endl; 
    }
}