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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        map<int, int> freq;
        int zeros = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != 0) freq[a[i]]++;
            else zeros++;
        }

        int ans = 0;
        for (auto &[val, count] : freq) {
            ans += count * (count - 1) / 2;
        }

        if (zeros > 0) {
            if (!freq.empty()) {
                int max_count = max_element(freq.begin(), freq.end(), 
                [](const pii &a, const pii &b) {
                    return a.second < b.second; })->second;

                int new_count = max_count + zeros;
                ans += new_count * (new_count - 1) / 2 - max_count * (max_count - 1) / 2;
            } else {
                ans = zeros * (zeros - 1) / 2;
            }
        }

        cout << ans << endl;
    }
}