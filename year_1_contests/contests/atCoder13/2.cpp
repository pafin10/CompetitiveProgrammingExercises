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
//#define int long long
const int MAX_N = 100'005;

int32_t main() {
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int xa, ya, xb, yb, xc,yc; 
    cin>>xa>>ya>>xb>>yb>>xc>>yc;

    int a2 = (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);
    int b2 = (xb - xc) * (xb - xc) + (yb - yc) * (yb - yc);
    int c2 = (xa - xc) * (xa -xc) + (ya - yc) * (ya - yc);

    if (a2 + b2 == c2 || b2 + c2 == a2 || a2 + c2 == b2) cout<<"Yes"<<endl; 
    else cout<<"No"<<endl; 
}