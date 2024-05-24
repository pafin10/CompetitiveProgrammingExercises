#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>


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
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
//#define int long long
const int MAX_N = 100'005;

int main(int argc, char const *argv[]) {
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t=1;//cin>>t; 
    while(t--) {
        int n; cin>>n; 
        vector<pair<pair<int, int>, int>> cards(n); 
        it(i,0,n) {
            cin>>cards[i].ff.ff;
            cin>>cards[i].ff.ss;
            cards[i].ss = i+1; 
        }
        sort(cards.rbegin(), cards.rend());
        int minCost = INT32_MAX;
        vi indices; 
        it(i,0,n) {
            if (cards[i].ff.ss <= minCost) indices.pb(cards[i].ss);
            if (cards[i].ff.ss < minCost) minCost = cards[i].ff.ss;
        }
        int m = indices.size();
        cout<<m<<endl; 
        sort(all(indices));
        it(i,0,m) cout<<indices[i]<<" "; 
        cout<<endl; 
    }
}