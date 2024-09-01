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

    while(t--) {
        int n; cin>>n; 
        vi a(n);

        int pos = 0, neg = 0, zero = 0;
        for (int j = 0; j < n; j++) {
            cin>>a[j];
        }
        int start = 0, last = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                pos++;
                if (start == 0) start = i+1; 
                last = i; 
            }
            else if (a[i] < 0) {
                if (start) neg++;
            }
        }

        int sub = 0;
        for (int i = last +1; i < n; i++) {
            if (a[i] < 0) sub++;
        }
        cout<<max(0, neg - sub)<<endl; 
    }
}