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
    // ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t=1;//cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string s; cin>>s;
        string ans = "Yes";
        if (n % 2 == 0) {
            cout<<"No"<<endl; 
            continue;
        } 
        for (int i = 0; i < n; i++) {
            if (i < n/2 && s[i] != '1') 
                ans = "No";
            else if (i == n / 2 && s[i] != '/') 
                ans = "No";
            else if (i > n/2 && s[i] != '2') ans = "No";
        }
        cout<<ans<<endl; 
    }
}