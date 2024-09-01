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
    //ifstream cin("2.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int n, k; 
        cin>>n>>k; 
        if (n==1) {cout<<k<<endl; continue;}
        int msbNum = 1;
        while((msbNum << 1) <= k) msbNum = msbNum<<1;

        cout<<msbNum-1<<" "<<k-(msbNum-1)<<" ";
        n-=2;
        while (n--) cout<<0<<" ";
        cout<<endl; 
    }
}