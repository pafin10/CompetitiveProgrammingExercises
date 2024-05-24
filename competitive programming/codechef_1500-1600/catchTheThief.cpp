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
#include <queue>


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
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
//#define int long long
const int MAX_N = 100'005;

int main(int argc, char const *argv[]) {
    //ifstream cin("catchTheThief.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n,k,x,y;
        cin>>x>>y>>k>>n;
        vi reachableThief, reachablePolice;
        int initDist = abs(x-y);

        string ans = "Yes";
        if (initDist%k==0 && (initDist/k)%2==1) ans = "No";
        int xStart = x%k == 0 ? k : x%k;
        int yStart = y%k == 0 ? k : y%k;
        if (xStart != yStart) ans = "No";
        cout<<ans<<endl; 
    }
}