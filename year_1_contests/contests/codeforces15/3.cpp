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
    //ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n;
        vll x(n-1), a(n); 
        it(i,0,n-1) cin>>x[i];

        a[0] = x[0]+1;
        it(i,1,n) {
            a[i] = a[i-1]+x[i-1];
            if (i < (n-1) && a[i] <= x[i]) {a[i]=x[i]+1; while(!(a[i]%a[i-1] == x[i-1])) a[i]++;}
        }
        it(i,0,n) cout<<a[i]<<" ";
        cout<<endl; 
    }
}