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
    //ifstream cin("whenToTakeMedicine.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        string s; cin>>s; 
        int y = stoi(s.substr(0,4));
        int m = stoi(s.substr(5, 7));
        int d = stoi(s.substr(8,10));

        vi leapY; 
        for (int i = 1904; i <= 2038; i+=4) leapY.pb(i);
        bool even = d%2==0;
        int ans = 0;
        vi longM; longM.pb(1), longM.pb(3), longM.pb(5), longM.pb(7), longM.pb(8),
        longM.pb(10), longM.pb(12);
        if (even) {
            if (find(all(longM), m) != longM.end()) ans = (30-d+2) / 2;            
            else {
                if (m == 2 && find(all(leapY), y) != leapY.end()) ans = (28 - d + 2) / 2;
                else {
                    ans = (30 - d + 2 + 30) / 2;
                    if (m==2) ans--;
                }
            }
        }
        else {
            if (find(all(longM), m) != longM.end()) ans = (31-d+2) / 2;  
            else {
                if (m == 2 && find(all(leapY), y) != leapY.end()) ans = (29 - d + 2) / 2;
                else {
                    ans = (30-d+2+31) / 2;
                    if (m==2) ans--;
                }
            }          
        }
        cout<<ans<<endl; 
    }
}