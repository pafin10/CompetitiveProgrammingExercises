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

int main(int argc, char const *argv[]) {
    //ifstream cin("concatPalindrome.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n, m; cin>>n>>m; 
        string a,b; 
        bool ans = true; 
        cin>>a>>b; 
        bool oddSum = (n+m)%2==1;
        vi charCnt(26,0);
        int odds = 0;
        if (n > m) {
            it(i,0,n) charCnt[a[i] - 'a']++;
            it(i,0,m) charCnt[b[i] - 'a']--;
        }
        else {
            it(i,0,m) charCnt[b[i] - 'a']++;
            it(i,0,n) charCnt[a[i] - 'a']--;
        }
        it(i,0,26) {
            if (charCnt[i]%2==1) {
                if (oddSum) {
                    odds++; 
                    if (odds > 1) ans = false; 
                }
                else ans = false; 
            }
            else if (charCnt[i] < 0) ans = false; 
        }
        ans ? cout<<"YES"<<endl : cout<<"NO"<<endl; 
        
    }
}