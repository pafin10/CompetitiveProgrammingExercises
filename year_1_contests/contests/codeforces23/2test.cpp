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
#define int long long
const int MAX_N = 100'005;

static bool isLarge(int n);
static bool isLarge(int n) {
    bool out = true;
    while (n) {
        int k = n%10;
        if (k < 5) {out = false; break;}
        n /= 10;
    }
    return out; 
}

int32_t main() {
    ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int x; cin>>x; 
        int ans = 1;
        if (x % 10 == 9) ans = 0;
        else {
            int numDigX = floor(abs(log10(x)) + 1);
            int k = x / 2;
            int numDigK = floor(abs(log10(k)) + 1);
            int minVal = (int)pow(10, numDigK-1);
            int maxVal = min(x, (int)pow(10, numDigK));

            if (numDigK == numDigX) ans = 0;
            else {
                int startK = max(minVal * 5, k);
                int endK = min(maxVal - 1, x - 5 * minVal);

                ans = 0;
                if ((endK / minVal) >= 5) {
                   for (int i = startK; i <= endK; ++i) {
                        if (isLarge(i) && isLarge(x - i)) {
                            ans = 1;
                            break;
                        }
                    } 
                }
                
            }
        }
        if (ans) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl; 
    }
}