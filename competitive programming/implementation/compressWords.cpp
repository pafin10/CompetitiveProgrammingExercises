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
    // ifstream cin("compressWords.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t=1;//cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string ans; 
        cin>>ans; 

        for (int i = 1; i < n; i++) {
            string s; cin>>s; 
            string text = s + "#";

            // construct reversed pref#relevantSuffix word
            for (int j = max(0, (int)ans.size() - (int)s.size()); j < (int)ans.size(); j++) text += ans[j];

            vi pi(text.size());
            pi[0] = -1; 
            // compute longest prefix that is also suffix via KMP
            for (int k = 1; k < text.size(); k++) {
                pi[k] = pi[k - 1];
                while (pi[k] != -1 && text[pi[k] + 1] != text[k]) pi[k] = pi[pi[k]];
                if (text[pi[k] + 1] == text[k]) pi[k]++;
            }

            for (int m = pi.back() + 1; m < s.size(); m++) ans += s[m];

        }
        cout<<ans<<endl; 
        
    }
}