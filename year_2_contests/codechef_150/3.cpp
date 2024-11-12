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
const int MAX_N = 100'005;
const int INF = 1E9;

int calculatePairs(int count) {
    return count * (count - 1) / 2;
}

int32_t main() {
    ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    // basically same as before just update entries in map and recalculate ans
    while (t--) {
        int n;
        cin >> n;

        vi a(n, 0);  
        unordered_map<int, int> freq;  
        int pairs = 0;  
        int zeros = n; 

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;  
            x--;  

            int oldVal = a[x], newVal = y;  

            if (oldVal != 0) {
                pairs -= calculatePairs(freq[oldVal]);
                freq[oldVal]--;
                pairs += calculatePairs(freq[oldVal]);
            }
            else zeros--;

            a[x] = newVal;

            if (newVal != 0) {
                pairs -= calculatePairs(freq[newVal]);
                freq[newVal]++;
                pairs += calculatePairs(freq[newVal]);
            }
            else zeros++;

            int maxFreq = 0;
            if (!freq.empty()) {
                maxFreq = max_element(freq.begin(), freq.end(),
                                      [](const pii &a, const pii &b) {
                                          return a.second < b.second;
                                      })->second;
            }

            int maxPairs = pairs + calculatePairs(maxFreq + zeros);
            cout << maxPairs << " ";
        }
        cout << endl;
    }
}