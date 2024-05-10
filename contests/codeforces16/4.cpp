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
    //ifstream cin("4.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        string s; cin>>s;
        int n = s.length();
        int trans = 0;
        bool sorted = true;
        it(i,0,n-1) {
            if (s[i+1] < s[i]) sorted = false; 
            if (s[i] != s[i+1]) trans++;
        }
        if (sorted) cout<<1<<endl;
        else if (trans == 1) cout<<2<<endl;
        else cout<<max(1,trans)<<endl;
    }
}