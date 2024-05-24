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
    ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t=1;//cin>>t; 
    while(t--) {
        ll a,b,c,d; cin>>a>>b>>c>>d; 
        ll ans = 0;
        double black = 0;
        // positive on x axis
        if (a>=0) {
            while(a < c && b < d) {
                if (a%4==1) black ++;
                else if (a%4==2 || a%4==3) black += 0.5;
                if (c%4==3 || c%4==2) black += 1.5;
                else if (c%4==1) black ++;
                if (b%4==1) black ++;
                else if (b%4==2 || a%4==3) black += 0.5;
                if (c%4==3 || c%4==2) black += 1.5;
                else if (c%4==1) black ++;
                a++;
                a++; b++;
            }
            if (a == c) {
                while (b<d) {
                    
                }
            }
            else if (b == d) {
                while (a < c) {
                    if (a%4==1) black ++;
                    else if (a%4==2 || a%4==3) black += 0.5;
                    if (c%4==3 || c%4==2) black += 1.5;
                    else if (c%4==1) black ++;
                    a++;
                }
            }
        }
        // all negative on x axis
        else if (a < 0 && c <= 0) {

        }
        // overlaps from neg to pos
        else {

        }
        cout<<ans<<endl; 
    }
}