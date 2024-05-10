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
const int MAX_N = 100'005;
ll INF = (ll)1e18;

int find(string s);
int find(string s) {
    ll sm = 0;
    for (auto i: s) sm += (i - '0');
    return sm%10;
}

int main(int argc, char const *argv[]) {
    // APPROACH: RUN BRUTE FORCE WITH SMALL NUMS, TRY TO IDENTIFY PATTERN
    //ifstream cin("gudduOnADate.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        string n; cin>>n; 
        int k = find(n);
        if (k==0) cout<<n+'0'<<endl; 
        else cout<<n+to_string(10-k)<<endl;
    }
}