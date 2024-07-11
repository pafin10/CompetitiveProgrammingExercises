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
#define int long long
const int MAX_N = 100'005;



int32_t main() {
    //ifstream cin("2.txt");
    int t;
    cin >> t;
    
    while (t--) {
        string x; 
        cin >> x;
        if (x[0] == '1' && x[sz(x)-1] != '9') {
            int ans = 1;
            it(i,0,sz(x)-1) if (x[i] == '0') {ans = 0; break;}
            ans ? cout<<"YES"<<endl : cout<<"NO"<<endl; 
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
