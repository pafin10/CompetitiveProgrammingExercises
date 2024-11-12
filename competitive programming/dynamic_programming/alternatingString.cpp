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
    //ifstream cin("alternatingString.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string s; 
        cin>>s; 

        map<char, int> odds, evens, all; 
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) evens[s[i]]++;
            else odds[s[i]]++;
            all[s[i]]++;
        }
        int ans = INT32_MAX;
        if (n % 2 == 0) {
            auto maxOdd = max_element(odds.begin(), odds.end(), 
            [] (const pii& a, const pii& b) {return a.ss < b.ss;}) -> second;
            auto maxEven = max_element(evens.begin(), evens.end(), 
            [] (const pii& a, const pii &b) {return a.ss < b.ss;}) -> second;

            ans = max(n / 2 - maxEven + n / 2 - maxOdd, 0);

            cout<<ans<<endl; 
        }
        
        else {
            vi pref[2] = {vi(26), vi(26)};
            vi suff[2] = {vi(26), vi(26)};

            for (int i = n - 1; i >= 0; i--) {
                suff[i%2][s[i] - 'a']++;
            }

            for (int i = 0; i < n; i++) {
                suff[i%2][s[i] - 'a']--;
                int res = n; 

                for (int k = 0; k < 2; k++) {
                    int mx = 0; 

                    for (int j = 0; j < 26; j++) {
                        mx = max(mx, suff[1 - k][j] + pref[k][j]);
                    }
                    res -= mx; 
                }
                ans = min(ans, res);
                pref[i % 2][s[i] - 'a']++;
            }
            cout<<ans<<endl; 
        }

        

        


    }
}