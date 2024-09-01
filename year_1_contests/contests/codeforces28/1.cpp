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
#include <cassert>


using namespace std;
#define NDEBUG
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
        string s; cin>>s;
        char k = s[0];
        bool ins = false; 
        for (int i = 1; i < s.size(); i++) {
            if (!ins && s[i] == s[i-1]) {
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if (ch != s[i]) {
                        s.insert(i, 1, ch);
                        ins = true;
                        break;
                    }
                }
            }
        }
        if (!ins) {
            if (k == 'a') s.insert(0, 1, 'b');
            else s.insert(0,1, 'a');
        }
        
        cout<<s<<endl; 
    }
}