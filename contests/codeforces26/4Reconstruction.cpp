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
#define int long long
const int MAX_N = 100'005;

int32_t main() {
    //ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string s; cin>>s; 
        vector<char> vs(all(s));
        vi nums(n);
        it(i,0,n) nums[i] = s[i] - '0';

        int zeroCnt = 0, oneCnt = 0, twoDigNum = 100;

        it(i,0,n) {
            if(nums[i] == 0) zeroCnt++; 
            else if(nums[i] == 1) oneCnt++;
        }
        if (zeroCnt > 0 && n > 2) {
            if (n > 3) {cout<<0<<endl; continue;}
            if ((n == 3) && (nums[0] == 0 || nums[2] == 0)) {cout<<0<<endl; continue;}
        }
        if (oneCnt == n) {cout<<11<<endl; continue;}

        int sum = 0, ans = LONG_MAX;
        it(i,0,n-1) {
            sum = 0;
            twoDigNum = nums[i]*10 + nums[i+1];
            sum += twoDigNum;
            it(j,0,n) {
                if (j != i && j != i+1) {
                    if (nums[j] == 1) continue;
                    else sum = sum == 1 ? sum*nums[j] : sum+nums[j];
                }
            }
            ans = min(ans, sum);
        }
        
        cout<<ans<<endl; 
    }
}