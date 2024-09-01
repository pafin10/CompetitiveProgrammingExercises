#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <numeric>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define rev(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define INF (ll)1e18

int main(int argc, char const *argv[]) {
    //ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int a,b,c,d; cin>>a>>b>>c>>d;
        string ans = "NO";
        int minA = min(a,b), maxA = max(a,b), minB = min(c,d), maxB = max(c,d);
        if ((minA < minB && maxA < maxB) && !(maxA < minB)) ans="YES";
        if ((minB<minA && maxB < maxA) && !(maxB < minA)) ans="YES";
        cout<<ans<<endl; 
    }
}