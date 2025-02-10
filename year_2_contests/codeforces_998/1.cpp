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
    // ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        vector<int> a(4);
        for (auto& i: a) cin>>i;

        int x = a[0] + a[1], y = a[2] - a[1], z = a[3] - a[2];

        int ans = 0;

        for (int i = 0; i < 3; i++) {
            int a_3, cnt = 0;
            if (!i) a_3 = x;
            else if (i == 1) a_3 = y;
            else a_3 = z;
            a.insert(a.begin() + 2, a_3);
            for (int j = 2; j < 5; j++) {
                if (a[j - 2] + a[j - 1] == a[j]) {
                    cnt++; 
                    ans = max(ans, cnt);
                }
            }
            a.erase(a.begin() + 2);
        }
        cout<<ans<<endl; 
    }
}