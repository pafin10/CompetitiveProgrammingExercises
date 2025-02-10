#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <array>
#include <deque>


using namespace std;
#define NDEBUG
#define ll long long
#define endl "\n"
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
const int INF = 1E9;

int32_t main() {
    // CHECK SOLUTION
    ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n;
        string s, p; 
        cin>>s>>p; 
        p = "_" + p; 

        map<char, char> m; 
        set<char> se;
        for (auto& i: s) se.insert(i);

        for (int i = 0; i < n; i++) {
            if (m.size() == se.size()) break; 
            int j; 
            for (j = 1; j <= 26; j++) {
                if (p[j] == s[i]) break; 
            }
            if (!m[s[i]]) {
                int x = 27 - j; 
                m[s[i]] = p[x];
            }
        }

        vi dp_1(n), dp_2(n);
        dp_1[n - 1] = 0; 
        dp_2[n - 1] = 1;
        
        vector<char> s_1(s.begin(), s.end()), s_2(s.begin(), s.end());
        s_2[n - 1] = m[s[n - 1]];

        for (int i = n - 2; i >= 0; i--) {
            if (s_1[i] - '0' <= s_1[i + 1] - '0') dp_1[i] = dp_1[i + 1];
            else {
                if (m[s_1[i + 1]] - '0' >= s_1[i] - '0') {
                    s_1[i + 1] = m[s_1[i + 1]];
                    dp_1[i] = dp_1[i + 1] + 1;
                }
                else if (m[s_1[i]] - '0' <= s_1[i + 1] - '0') {
                    s_1[i] = m[s_1[i]];
                    dp_1[i] = dp_1[i + 1] + 1;
                }
                else if (i < n - 2 && m[s_1[i + 1]] - '0' >= s_1[i] - '0' && 
                m[s_1[i + 1]] - '0' <= s_1[i + 2] - '0') {
                    dp_1[i] = dp_1[i + 1] + 1;
                    s_1[i + 1] = m[s_1[i + 1]];
                }
                else {
                    if (m[s_1[i]] - '0' <= m[s_1[i + 1]] - '0') {
                        dp_1[i + 1]++;
                        dp_1[i] = dp_1[i + 1] + 1; 
                        s_1[i + 1] = m[s_1[i + 1]];
                        s_1[i] = m[s_1[i]];
                        if (i < n - 2 && m[s_1[i + 1]] - '0' > s_1[i + 2] - '0') i++;
                    }
                    else {
                        dp_1[0] = -1;
                        break; 
                    }
                }
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (s_2[i] - '0' <= s_2[i + 1] - '0') dp_2[i] = dp_2[i + 1];
            else {
                if (m[s_2[i + 1]] - '0' >= s_2[i] - '0') {
                    s_2[i + 1] = m[s_2[i + 1]];
                    dp_2[i] = dp_2[i + 1] + 1;
                }
                else if (m[s_2[i]] - '0' <= s_2[i + 1] - '0') {
                    s_2[i] = m[s_2[i]];
                    dp_2[i] = dp_2[i + 1] + 1;
                }
                else if (i < n - 2 && m[s_2[i + 1]] - '0' >= s_2[i] - '0' && 
                m[s_2[i + 1]] - '0' <= s_2[i + 2] - '0') {
                    dp_2[i] = dp_2[i + 1] + 1;
                    s_2[i + 1] = m[s_2[i + 1]];
                }
                else {
                    if (m[s_2[i]] - '0' <= m[s_2[i + 1]] - '0') {
                        if (m[s_2[i]] - '0' <= m[s_2[i + 1]] - '0') {
                        dp_2[i + 1]++;
                        dp_2[i] = dp_2[i + 1] + 1; 
                        s_2[i + 1] = m[s_2[i + 1]];
                        s_2[i] = m[s_2[i]];
                        if (i < n - 2 && m[s_2[i + 1]] - '0' > s_2[i + 2] - '0') i++;
                    }
                    else {
                        dp_2[0] = -1;
                        break; 
                    }
                }
            }
        }
        }

        cout<<string(s_1.begin(), s_1.end())<<endl; 
        cout<<string(s_2.begin(), s_2.end())<<endl; 
        if (dp_1[0] != -1 && dp_2[0] != -1) cout<<min(dp_1[0], dp_2[0])<<endl;
        else if (dp_1[0] != -1) cout<<dp_1[0]<<endl; 
        else if (dp_2[0] != -1) cout<<dp_2[0]<<endl; 
        else cout<<-1<<endl;  
    }
}