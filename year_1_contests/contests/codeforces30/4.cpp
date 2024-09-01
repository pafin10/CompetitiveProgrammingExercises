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
    //ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        string s, k; cin>>s>>k;
        int n = s.length();
        int m = k.length();

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == k[j] || s[i] == '?') j++;
        }
        // j covered
        if (j < k.length()) {
            cout<<"NO"<<endl; 
        }
        else {
            j = 0;
            cout<<"YES"<<endl;
            for (int i = 0; i < n; i++) {
                if (j < n) {
                    if (s[i] == '?') {
                        if (j < m) cout<<k[j];
                        else cout<<'z';
                        j++;
                    }
                    else {
                        if (s[i] == k[j]) {
                            cout<<s[i];
                            j++;
                        }
                        else cout<<s[i];
                    }
                }
            }
                
            cout<<endl; 
        }
    }
}