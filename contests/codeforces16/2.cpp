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
#include <bitset>
#include <numeric>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define rev(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define INF (ll)1e18

int main(int argc, char const *argv[]) {
    //ifstream cin("2.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        string s; cin>>s; 
        int n = s.length();
        bool pos = false; 
        vector<char> r(n);
        char first = s[0];
        it(i,0,n) {
            if (s[i] != first && !pos) {r[0] = s[i]; r[i] = s[0]; pos = true; first='_';}
            else r[i] = s[i];
        }
        string ans(all(r));
        if (pos) {cout<<"YES"<<endl; cout<<ans<<endl;}
        else cout<<"NO"<<endl; 
    }
}