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
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 
        if (n == 1 && k == 1) {
            cout<<1<<endl; 
            cout<<1<<endl;
            continue;
        }

        if (n != k && k != 1) {
            cout<<3<<endl; 
            if (k % 2 == 0) {
                cout<<1<<" "<<k<<" "<<k + 1<<endl; 
            }
            else {
                cout<<1<<" "<<k - 1<<" "<<k + 2<<endl;
            }
        }
        else cout<<-1<<endl; 
    }
}