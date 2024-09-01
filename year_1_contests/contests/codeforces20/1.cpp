#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_map>
#include <cctype>


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
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
//#define int long long
const int MAX_N = 100'005;

int32_t main() {
    //ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string s; cin>>s; 
        bool letter = false; 
        int lastNum = 0;
        char lastChar = 'a';
        string ans = "YES";
        it(i,0,n) {
            if (isalpha(s[i])) letter = true; 
            if (letter && isdigit(s[i])) {ans = "NO"; break;}
            if (isdigit(s[i])) {
                if (s[i] - '0' < lastNum) {ans = "NO"; break;}
                if (s[i] - '0' > lastNum) lastNum = s[i] - '0';
            }
            else if (isalpha(s[i])) {
                if (s[i] < lastChar) {ans = "NO"; break;}
                if (s[i] > lastChar) lastChar = s[i];
            }
        }
        cout<<ans<<endl; 
    }
}