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
    //ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int n, k; cin>>n>>k; 
        vector<bool> b(k, false);
        it(i,0,n) {
            string s; cin>>s; 
            int ind = 0;
            bool setBit = false;
            it(i,0,k) {
                if (s[i] == '1') {
                    if (ind == 0 && !setBit) {ind = i; setBit = true;}
                    else if(setBit) setBit = false;
                } 
            }
            if (setBit) b[ind] = true;
        }
        string ans = "YES";
        it(i,0,k) {if (!b[i]) {ans = "NO"; break;}}
        cout<<ans<<endl; 
    }
}