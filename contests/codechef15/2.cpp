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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        string s; cin>>s; 
        vi pos; 
        it(i,0,5) {
            if (s[i] == '1') pos.pb(i);
        }
        int k = pos.size();
        if (k == 1) {
            cout<<11<<endl; 
        }
        else if (k == 2) {
            if ((pos[0] == 0 && pos[1] == 1) || (pos[0] == 2 && pos[1] == 3)) cout<<21<<endl; 
            else cout<<121<<endl; 
        }
        else if (k == 3) {
            cout<<231<<endl; 
        }
        else {
            cout<<441<<endl;
        }
    }
}