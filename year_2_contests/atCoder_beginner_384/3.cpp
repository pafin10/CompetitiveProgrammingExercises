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
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d, e; 
    cin>>a>>b>>c>>d>>e; 

    vector<string> subsets = {
        "ABCDE", "BCDE", "ACDE", "ABDE", "ABCE", "ABCD",
        "CDE", "BDE", "ADE", "BCE", "ACE", "BCD",
        "ABE", "ACD", "ABD", "ABC",
        "DE", "CE", "BE", "CD", "AE", "BD", "AD", "BC", "AC", "AB",
        "E", "D", "C", "B", "A"
    };
    map<char, int> m; 
    m['A'] = a; m['B'] = b; m['C'] = c; m['D'] = d; m['E'] = e; 
    
    vector<pair<string, int>> scored(31);
    for (int i = 0; i < 31; i++) {
        scored[i] = {subsets[i], 0}; 
        for (auto c : subsets[i]) {
            scored[i].ss += m[c];
        }
    }
    sort(scored.begin(), scored.end(), [](const pair<string, int> a,
     const pair<string, int> b) {
        if (a.ss != b.ss)
            return a.ss > b.ss;
        else 
            return a.ff < b.ff;
     });

    for (auto el: scored) {
        cout<<el.ff<<endl; 
    }

    
}