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
const int MAX_N = 100'005;

int main(int argc, char const *argv[]) {
    //ifstream cin("chefDrinksCoke.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n,m,k,l,r; cin>>n>>m>>k>>l>>r; 
        int minPrice = INT32_MAX;
        it(i,0,n) {
            int c,p; cin>>c>>p;
            if (c < k) {
                c += min(m, k-c);
                if (l <= c && c <=r && p < minPrice) minPrice = p; 
            }
            else if (c > k) {
                c -= min(m, c-k);
                if (l <= c && c <=r && p < minPrice) minPrice = p;
            }
            else {
                if (l <= c && c <=r && p < minPrice) minPrice = p;
            }
        }
        if (minPrice != INT32_MAX) cout<<minPrice<<endl; 
        else cout<<-1<<endl;
    }
}