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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        string b; cin>>b; 
        vector<bool> used(26, false);

        vector<char> a;
        it(i,0,n) {
            if (!used[b[i] - 'a']) {
                a.pb(b[i]);
                used[b[i] - 'a'] = true; 
            }
        } 
        sort(all(a));
        int k = sz(a);
        map<char, int> mp; 
        it(i,0,k) mp[a[i]] = (k-i-1); 
        vector<char> ans(n); 

        it(i,0,n) {
            ans[i] = a[mp[b[i]]];
        }
        string sAns(all(ans));
        cout<<sAns<<endl; 
    }
}