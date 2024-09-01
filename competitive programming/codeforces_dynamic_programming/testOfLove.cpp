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
    //ifstream cin("testOfLove.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m, k; cin>>n>>m>>k; 
        string a; 
        cin>>a; 
        int i = -1, cnt = 0;
        char curr = 'L';
        int ans = 1;
        while (i < n && cnt <= k) {
            int tmp = i; 
            if (curr == 'L') {
                if (i + m >= n) break;
                for (int j = m; j > 0; j--) {
                    if (a[i+j] == 'L') {
                        i += j; 
                        curr = 'L';
                        break; 
                    }
                }
                if (tmp == i) {
                    for (int j = m; j > 0; j--) {
                        if (a[i+j] == 'W') {
                            i += j; 
                            curr = 'W';
                            break;
                        }
                    }
                    if (tmp == i) {
                        ans = 0;
                        break; 
                    }
                }
            }
            else if (curr == 'W') {
                i++;
                cnt++;
                curr = a[i];
            }
            else {
                ans = 0;
                break; 
            }
        }
        if (cnt > k || ans == 0) cout<<"NO"<<endl; 
        else cout<<"YES"<<endl; 
    }
}