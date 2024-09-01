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
#define sz(x) (int)x.size()

int main(int argc, char const *argv[]) {
    //ifstream cin("4.txt");
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n;
        vll a(n);
        ll ans = 0; int cnt = 0;
        bool odd = false; 
        int last = 0;
        it(i,0,n) {
            cin>>a[i];
            if(a[i]%2==1) odd=true;
            if (a[i]%2==0) {
                if (ans!=0) ans += i-last-1;
                ans += (i+1);
                last = i;
                cnt++;
            }
            if (i==(n-1) && (a[i]%2)!=0) ans += (i - last +1);
        }
        if (odd) ans += (n-cnt);
        cout<<ans<<endl; 
    }
}