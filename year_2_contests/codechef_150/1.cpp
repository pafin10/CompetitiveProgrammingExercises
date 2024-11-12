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
    //ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while (t--) {
        int n, k;
        cin >> n >> k;
        
        multiset<int> ms;
        int x;
        
        for (int i = 0; i < n; i++) {
            cin >> x;
            ms.insert(x);
        }
        
        while (k-- && ms.size() > 1) {
            auto minIt = ms.begin();            
            auto maxIt = prev(ms.end());         
            int minVal = *minIt;                  
            int maxVal = *maxIt;                  
            
            ms.erase(minIt);                    
            ms.erase(maxIt);                     
            
            ms.insert(minVal + maxVal);
        }
        
        for (auto it = ms.begin(); it != ms.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}