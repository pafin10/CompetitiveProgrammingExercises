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
    ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        int maxSum = 0, numOps = 0;
        vi app;
        vector<vi> out;
        it(i, 0, n) app.pb(i+1);

        it(i,0,n) {
            vi el; el.pb(1), el.pb(i+1);
            out.pb(el); out.pb(app);
        }

        numOps = n;
        maxSum = n * (n*(n+1)/2);
        int lim = n/2;
        it(i,0,lim) {
            maxSum += ((n*(n+1)/2) - (n*(i+1)));
            numOps++;
            vi el; el.pb(2); el.pb(i+1);
            out.pb(el); out.pb(app);
        }
        if (n%2==0) {
            numOps++;
            maxSum += (n/2*(n/2+1)/2) - (n/2);
            vi el; el.pb(1); el.pb(1);
            out.pb(app);
        }
        cout<<maxSum<<" "<<numOps<<endl; 
        it(i,0,out.size()) {
            for (int j = 0; j < out[i].size(); j+= 2) {
                if (out[i].size()-j > 1) {cout<<out[i][j]<<" "; cout<<out[i][j+1]<<" ";} 
                else cout<<out[i][j]<<" ";
            }
            cout<<endl; 
        }
        cout<<endl; 
    }
}