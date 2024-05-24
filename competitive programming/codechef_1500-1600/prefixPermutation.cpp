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
const int MAX_N = 100'005;

int main(int argc, char const *argv[]) {
    //ifstream cin("prefixPermutation.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n, k; cin>>n>>k; 
        vi a(k);
        it(i,0,k) cin>>a[i];

        sort(all(a));
        vi perm(n);
        int j = 0;
        for (j = 0; j < k; j++) {
            int cnt = 0;
            for (int i = a[j]; (j==0 ? i >= 1 : i > a[j-1]); i--) {
                if (j) perm[a[j]+a[j-1]-i] = i;  
                else perm[a[j]-i] = i;  
                cnt++;
            }
        }
        vout(perm);
        cout<<endl; 
    }
}