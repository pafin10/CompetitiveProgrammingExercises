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
    //ifstream cin("chefGoesToTheCinema.txt");
    const int MAX_SIZE = 1'000'000'000;
    vll dist;
    dist.pb(0), dist.pb(1);
    it(i,2,MAX_SIZE) {
        dist.pb(dist[i-1] + i);
        if (dist[i] > MAX_SIZE) break; 
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int x; cin>>x; 
        int l = 1, r = dist.size()-1;
        while (l<r) {
            int mid = (l+r) / 2;
            if (dist[mid] < x) l = mid+1; 
            else r = mid; 
        }
        int ans = dist[l] > x ? (min(l+(abs(dist[l]-x)), l-1+(abs(dist[l-1]-x)))) : 
                (min(l+(abs(dist[l]-x)), l+1+(abs(dist[l+1]-x))));
        cout<<ans<<endl;
    }
}