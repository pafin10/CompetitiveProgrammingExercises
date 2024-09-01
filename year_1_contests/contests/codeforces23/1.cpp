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
    //ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n); 
        bool same = true;
        int chInd = 0;
        set<int> s; 
        it(i,0,n) {
            cin>>a[i];
            s.insert(a[i]);
            if (i && a[i] != a[i-1]) same = false; 
            else if (i && a[i] == a[i-1]) chInd = i; 
        }
        if (same) {cout<<"NO"<<endl; continue;}
        bool ch = false; 
        cout<<"YES"<<endl; 
        if (sz(s) == 2) {
            it(i,0,n) {
                if (i < chInd) cout<<"B";
                else cout<<"R";
            }
        }
        else {
            it(i,0,n) {
                if (i) cout<<"B";
                else cout<<"R";
            }
        }
        
        cout<<endl; 

    }
}