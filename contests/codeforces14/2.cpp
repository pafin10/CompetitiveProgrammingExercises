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

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

int main(int argc, char const *argv[]) {
    //ifstream cin("2.txt");
    // LONG LONG!!!
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        string s; cin>>s; 
        int n = s.length(), start = 0;
        ll ans = 0;
        bool count = false;
        it(i,0,n) {
            if (s[i] == '1' && !count) {count = true; start = i;}
            else if (s[i] == '0' && count) {
                ans += (i-start+1);
                start++;
            }
        }
        cout<<ans<<endl; 
    }
}