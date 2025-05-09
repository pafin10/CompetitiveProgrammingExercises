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
#include <deque>


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

int32_t main() {
    //ifstream cin("concatenationOfArrays.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<pair<int, int>> A(n); 
        map<int, vector<pair<int, int>>> sums; 

        for (int i = 0; i < n; i++) {
            cin>>A[i].first>>A[i].second;
            sums[A[i].first + A[i].second].push_back(A[i]); 
        }
        
        for (auto i: sums) {
            vector<pair<int, int>> p = i.second; 
            for (auto el : p) cout<<el.first<<" "<<el.second<<" ";
        }
        cout<<endl; 
    }
}