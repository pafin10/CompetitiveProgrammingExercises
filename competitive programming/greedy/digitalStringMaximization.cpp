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
#include <deque>


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
    // ifstream cin("digitalStringMaximization.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        string s; cin>>s; 
        int n = s.size();
        vector<char> s_vec(s.begin(), s.end());
        
        for (int i = 1; i < n; i++) {
            int j = i; 
            while ((j && s_vec[j]) && (s_vec[j] - 1 > s_vec[j - 1])) {
                s_vec[j]--;
                swap(s_vec[j], s_vec[j - 1]);
                j--;
            }
        }
        
        
        cout<<string(s_vec.begin(), s_vec.end())<<endl;
    }
}