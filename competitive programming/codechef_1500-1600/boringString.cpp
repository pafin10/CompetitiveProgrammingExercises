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


using namespace std;
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
//#define int long long
const int MAX_N = 100'005;

static map<char, vi> findBoringSubstrings(string s);

static map<char, vi> findBoringSubstrings(string s) {
    int n = s.length();
    map<char, vi> charLength; 
    int maxi = -1, letterSubs = 1;
    int currLength = 1;
    bool severalDifferent = false; 

    it(i,1,n) {
        if (s[i] == s[i-1]) {
            severalDifferent = false;
            currLength++;
            charLength[s[i]].pb(currLength);
        }
        else {
            if (severalDifferent) {
                charLength[s[i-1]].pb(currLength);
                if (i == n-1) charLength[s[i]].pb(currLength);
            }
            currLength = 1;
            severalDifferent = true; 
        }
    }
    map<char, vi> out; 
    for (auto& entry: charLength) {
        if (entry.ss.size() >= 2) out[entry.ff] = entry.ss;
    }
    return out; 
};


int32_t main() {
    //ifstream cin("boringString.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        map<char, vi> a = findBoringSubstrings(s);
        if (a.empty()) {cout<<0<<endl; continue;}

        int maxi = -1;
        for (auto& el: a) {
            sort(all(el.ss));
            if (el.ss[el.ss.size()-2] > maxi) {
                maxi = el.ss[el.ss.size()-2]; 
            }
        }
        cout<<maxi<<endl; 
    }
}