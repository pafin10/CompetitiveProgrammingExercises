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
#include <array>


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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string s; cin>>s; 

        string ans = "Yes";
        if (n == 4) {
            for(auto& el: s) if (el != '1') ans = "No";
            cout<<ans<<endl; 
            continue;
        }
        int zeroCnt = 0;
        int rowLength = n / (int) sqrt(n);
        if (rowLength * rowLength != n) ans = "No";

        vi zeroIndices; 
        bool start = false; 
        for (int i = 0; i < n; i++) {
            if (i < rowLength + 1 && s[i] == '0') ans = "No"; 
            if (i == rowLength + 1) {
                if (s[i] == '1') ans = "No";
                start = true;
            }
            if (start && s[i] == '0') {
                zeroIndices.pb(i);
                zeroCnt++;
            }
        }
        int expectedZeros = (rowLength - 2) * (rowLength - 2);
        if (expectedZeros != zeroCnt) ans = "No";

        int blockCnt = 1;
        for (int i = 0; i < sz(zeroIndices); i++) {
            int j = i; 
            if (j && zeroIndices[j] != zeroIndices[j-1] + 1) {
                if (zeroIndices[j] - zeroIndices[j-1] != 3) ans = "No";
                blockCnt = 1;
            }
            else if (j && zeroIndices[j] == zeroIndices[j-1] + 1) blockCnt++;
            if (blockCnt > (rowLength - 2)) ans = "No";
        }

        cout<<ans<<endl; 
                
    }
}