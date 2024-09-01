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

int main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while (t--) {
        int n;
        cin>>n;
        vi p(n);
        
        for (int i = 0; i < n; i++) cin>>p[i], p[i]--; 

        string s;
        cin>>s;

        vector<bool> visited(n, false);
        vi F(n, 0); 

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vi cycle;
                int current = i;

                while (!visited[current]) {
                    visited[current] = true;
                    cycle.pb(current);
                    current = p[current];
                }

                int totalBlacks = 0;
                for (int pos : cycle) {
                    if (s[pos] == '0') totalBlacks++;
                }

                for (int pos : cycle) {
                    F[pos] = totalBlacks;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << F[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
