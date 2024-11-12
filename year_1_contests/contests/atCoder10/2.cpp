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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin>>s; 
    int lower = 0, upper = 0;
    it(i,0,sz(s)) {
        if (islower(s[i])) lower++;
        else upper++;
    }
    if (lower > upper) {
        transform(all(s), s.begin(), [](unsigned char c) { return std::tolower(c); });
    } else {
        transform(all(s), s.begin(), [](unsigned char c) { return std::toupper(c); });
    }
    cout<<s<<endl; 
}