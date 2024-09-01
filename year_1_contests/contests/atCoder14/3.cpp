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


using namespace std;
#define NDEBUG
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define itb(i, start, n) for (int i = start; i >= n; --i)
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

int32_t main() {
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin>>n>>k; 
    string s; cin>>s;
    vector<string> permutations; 

    sort(all(s));
    do permutations.pb(s);
    while (next_permutation(s.begin(), s.end()));

    int cnt = 0;
    for (auto& p : permutations) {
        bool pal = true;
        int i = 0;
        while (i <= n - k) {
            pal = true; 
            int j = i; 
            for (j = 0; j < k / 2; j++) {
                if (p[i+j] != p[i+k-1-j]) {
                    pal = false; 
                    break; 
                }
            }
            if (pal) break; 
            i++;
        } 
        if (!pal) cnt++;
    }
    cout<<cnt<<endl; 
}