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
    ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string s; cin>>s; 
        vector<char> vs(all(s));
        vi nums(n);
        it(i,0,n) nums[i] = s[i] - '0';
        
        int twoDigNum = 1000, twoDigNum1 = 1000;
        int zeroCnt = 0, oneCnt = 0, ans = 1;

        int sum = 0, mini = 10;
        it(i,0,n) {
            if (nums[i] == 0) zeroCnt++;
            if (nums[i] == 1) oneCnt++;
            sum += (nums[i] == 1) ? 0 : nums[i];
            if (i < n-1) twoDigNum = min(twoDigNum, nums[i]*10 + nums[i+1]);
            if (nums[i] != 1 && nums[i] < mini) mini = nums[i];
        }

        if (zeroCnt > 0) {
            if (n > 3) {cout<<0<<endl; continue;}
            if (n==3) {
                if (zeroCnt > 1) {cout<<0<<endl; continue;}
                if (zeroCnt == 1 && nums[1] != 0) {cout<<0<<endl; continue;}
            } 
        }
        if (n == 2) {cout<<twoDigNum<<endl; continue;}
        if (n == 3) {
            ans = min(nums[0]*10+nums[1] + nums[2], min(nums[0]*10+nums[1] * nums[2], 
            min(nums[1]*10+nums[2] + nums[0], nums[1]*10+nums[2] * nums[0])));
            cout<<ans<<endl; 
            continue;
        }

        if (twoDigNum/10 == 1 || twoDigNum%10 == 1) {
            it(i,0,n) {
                if (i < n-1 && nums[i]*10 + nums[i+1] != twoDigNum) 
                    twoDigNum1 = min(twoDigNum1, nums[i]*10 + nums[i+1]);
            }
        }
        int k = min(twoDigNum1, twoDigNum + mini);
        
        if (k == twoDigNum + mini) {
            if (twoDigNum / 10 != 1) sum -= twoDigNum / 10;
            if (twoDigNum % 10 != 1) sum -= twoDigNum % 10;
            ans = sum + twoDigNum;
        }
        else {
            if (twoDigNum1 / 10 != 1) sum -= twoDigNum1 / 10;
            if (twoDigNum1 % 10 != 1) sum -= twoDigNum1 % 10;
            ans = sum + twoDigNum1;
        }

        cout<<ans<<endl; 

    }
}