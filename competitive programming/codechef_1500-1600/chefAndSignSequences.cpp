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
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
//#define int long long
const int MAX_N = 100'005;

int main(int argc, char const *argv[]) {
    //ifstream cin("chefAndSignSequences.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        string s; cin>>s;
        int n = s.length();
        int cnt1 = 1, cnt2 = 1;
        int maxi1 = 1, maxi2 = 1;
        it(i,0,n) {
            if (s[i] == '<') {
                cnt1++; 
                maxi1 = max(maxi1, cnt1);
                cnt2 = 1;    
            }
            else if (s[i] == '>') {
                cnt2++; 
                maxi2 = max(maxi2, cnt2);
                cnt1 = 1;
            }
        }
        cout<<max(maxi1, maxi2)<<endl; 
    }
}