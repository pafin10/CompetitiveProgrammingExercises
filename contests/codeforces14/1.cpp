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

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

int main(int argc, char const *argv[]) {
    //ifstream cin("1.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int ans = 3;
        int n; cin>>n;
        vi a(n); 
        it(i,0,n) cin>>a[i];
        it(i,0,n) {
            if (a[a[i]-1] == i+1) ans = 2;
        }
        cout<<ans<<endl; 
    }
}