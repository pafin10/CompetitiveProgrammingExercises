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
    //ifstream cin("flipTheString.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        string a,b; cin>>a>>b; 
        int n = a.length();
        int ans = 0;
        bool addOdd = false, addEven = false;
        vector<char> odds, evens;
        it(i,0,n) {
            if (a[i] != b[i]) {
                if (!(i%2)) {
                    if (evens.empty()) {ans++; evens.pb(a[i]);}
                    else if (addEven) {ans++; addEven=false;}
                }
                else if (i%2) {
                    if (odds.empty()) {ans++; odds.pb(a[i]);}
                    else if (addOdd) {ans++; addOdd=false;}
                }
            }
            else {
                if (!odds.empty() && (i%2)) addOdd = true; 
                else if (!evens.empty() && !(i%2)) addEven = true; 
            }
        }
        cout<<ans<<endl; 
    }
}