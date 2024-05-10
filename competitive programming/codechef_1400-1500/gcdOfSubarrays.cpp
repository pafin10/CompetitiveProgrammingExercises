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
    //ifstream cin ("gcdOfSubarrays.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        ll n, k; cin>>n>>k; 
        if (k < (n-1) * n / 2) {cout<<-1<<endl; continue;}
        else if (n==1) {cout<<k<<endl; continue;}
        else if (n==2) {cout<<1<<" "<<k-2<<endl; continue;}
        vll ans(n);
        it (i,0,n-2) ans[i] = 1;
        ll filled = n * (n+1) / 2 - 3;
        ll el = (k-filled) / 3;
        if (el > 0 && k - filled % 3 != 0) {
            ans[n-2] = el; ans[n-1] = el;
            ans[0] += ((k-filled)%3);
            while (ans[n-1] % ans[0] == 0) {
                ans[n-1]--; ans[n-2]--; ans[0]+=3;
            }
        } 
        else {cout<<-1<<endl; continue;}
        it (i,0,n) cout<<ans[i]<<" ";
        cout<<endl; 
    }
}