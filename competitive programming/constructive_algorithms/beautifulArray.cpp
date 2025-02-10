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
    // ifstream cin("beautifulArray.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin>>t; 

    while(t--) {
        int a, b; cin>>a>>b; 
        deque<int> d; 
        d.push_back(b);

        int left = a * 3 - b; 
        int ba = b - 1;
        left -= ba; 
        int f = left; 
        while (!(ba <= b && b <= f) || !f || !ba) {
            f++; ba--;
        }

        d.push_front(f);
        d.push_back(ba);
        
        cout<<(int)d.size()<<endl; 
        for (auto& el: d) cout<<el<<" ";
        cout<<endl; 
    }
}