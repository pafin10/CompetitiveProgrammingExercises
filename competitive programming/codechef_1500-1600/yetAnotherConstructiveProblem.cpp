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

int32_t main() {
    //ifstream cin("yetAnotherConstructiveProblem.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int x; cin>>x; 
        vi bits(31); int j = 0, last = 0; 
        int msb = 31 - __builtin_clz(x);
        int a = 0,b = 0,c = 0;


        it(i, 0, msb+2) {
            if (x & 1) {
                if (i % 3 == 0) {a |= (1 << i), b |= (1 << i);}
                else if (i % 3 == 1) {a |= (1 << i), c |= (1 << i);}
                else {b |= (1 << i), c |= (1 << i);}
            }
            else {
                if (i % 3 == 0) a |= (1 << i);
                else if (i % 3 == 1) b |= (1 << i);
                else c |= (1 << i);
            }
            x >>= 1;
        }
        
        cout<<a<<" "<<b<<" "<<c<<endl; 
        //cout<<((a | b) & (a | c) & (b | c))<<endl;  
    }
}