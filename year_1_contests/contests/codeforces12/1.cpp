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
    //ifstream cin("1.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int k,q; cin>>k>>q; 
        vi a(k), freqs(105, 0);
        freqs[0] = 0;
        int ind = 1;
        it(j,0,k) cin>>a[j];
        for (int i = 1; i <= 101; i++) {
            it(j, 0, k) {
                if (i==a[j]) {
                    freqs[i]++;
                    break;
                }
                freqs[i]=freqs[i-1];
            }
        }
  
        it(i,0,q) {
            int m; cin>>m; 
            while(freqs[m] != 0) {
                m -= freqs[m];
            }
            cout<<m<<" "; 
        }
        cout<<endl; 

    }
}