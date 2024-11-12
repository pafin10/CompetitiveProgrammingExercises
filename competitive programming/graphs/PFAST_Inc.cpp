#include <iostream>
#include <utility>
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


bool checkSubset(bitset<16> &bs, map<int, vi> &adjList) {
    int n = sz(adjList);
    bool valid = true; 

    for (int i = 0; i < n; i++) {
        if (bs[i]) {
            auto it = adjList.begin();
            advance(it, i);
            int el = it -> first;
            vi bad = it -> second; 

            if (bs[el]) {
                for (auto& match: bad) {
                    if (bs[match]) {
                        valid = false; 
                        break; 
                    }
                }
            }
            
            if (!valid) break; 
        }
    }
    return valid; 
}


int32_t main() {
    //ifstream cin("PFAST_Inc.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin>>n>>m;
    map<string, int> members; 
    vector<pair<int, int>> badPairs(m); 

    for (int i = 0; i < n; i++) {
        string member; cin>>member; 
        members[member] = 0;
    }
    int i = 0; 
    for (auto& member : members) {
        member.ss = i; 
        i++;
    }

    for (int i = 0; i < m; i++) {
        string a, b; cin>>a>>b; 
        badPairs[i].ff = members[a];
        badPairs[i].ss = members[b];
    }
    
    map<int, vi> adjList; // use indices directly, not strings
    int maxi = 0; 
    for (auto& entry : badPairs) {
        adjList[entry.ff].pb(entry.ss);
        adjList[entry.ss].pb(entry.ff);
        maxi = max(maxi, entry.ff);
    }
    for (int i = 0; i <= maxi; i++) {
        if (adjList.find(i) == adjList.end()) {
            adjList[i] = vi(); 
        }
    }

    bitset<16> maxSubset;
    int ans = 0; 

    for (int j = 0; j < (1 << n); ++j) { 
        bitset<16> bs(j); // Create bitset directly from integer j
        if (checkSubset(bs, adjList)) {
            int count = (int)bs.count();
            if (count > ans) {
                ans = count;
                maxSubset = bs;
            }
        }
    }
    cout<<ans<<endl; 
    vector<string> names; 
    for (int i = 0; i < n; i++) {
        if (maxSubset[i]) {
            auto it = members.begin();
            advance(it, i);
            names.pb(it -> first);
        }
    }
    for (auto& name: names) {
        cout<<name<<endl; 
    }
}