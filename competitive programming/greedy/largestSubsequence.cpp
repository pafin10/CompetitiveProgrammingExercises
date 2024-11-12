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
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

int main(int argc, char const *argv[]) {
    //ifstream cin("largestSubsequence.txt");
    int t; cin>>t; 
    while(t--) {
        // STEPS: 1. find ss. 2. compute # operations necessary. 3. check if ss can be sorted
        int n; cin>>n; 
        string s; 
        cin>>s; 
        vi subs; 
        it(i,0,n) {
            while(!subs.empty() && s[subs.back()] < s[i]) subs.pop_back();
            subs.pb(i);
        }
        int k = subs[0], i = 1;
        int ans = 0;
        while(i < subs.size() && s[k] == s[subs[i]]) {ans++; i++;}
        ans = subs.size()-1-ans; 
        int lim = subs.size()-1;

        it(i,0,subs.size()) if (i < lim-i) swap(s[subs[i]], s[subs[lim-i]]);
        it(i,1,n) if(s[i] < s[i-1]) {ans=-1; break;}
        cout<<ans<<endl; 
    }
}