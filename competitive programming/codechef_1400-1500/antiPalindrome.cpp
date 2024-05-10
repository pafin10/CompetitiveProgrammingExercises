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
    //ifstream cin("antiPalindrome.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        vi occur(26, 0);
        int n; cin>>n; 
        string s; cin>>s; 

        it(i,0,n) occur[s[i] - 'a']++;
        int ans = 0, cnt = 0;
        it(i,0,26) if(occur[i] != 0) cnt++;
        if (cnt == n) ans = 0;
        else if (cnt==1) {
            ans = (n%2==0) ? 1 : ans = 2; 
        }
        else {
            it(i,0,26) if(occur[i]%2==1) ans++; 
            if (n%2==0) ans == 0 ? ans = 1 : ans = 0; 
            else ans>1 ? ans = 0 : ans = 1;
        }
        cout<<ans<<endl; 
       
    }
}