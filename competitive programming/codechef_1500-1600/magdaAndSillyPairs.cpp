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
    ifstream cin("magdaAndSillyPairs.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        vll evensA, evensB, oddsA, oddsB;
        ll ans = 0;
       
        it(i,0,n) {ll j; cin>>j; j%2 == 0 ? evensA.pb(j) : oddsA.pb(j);}
        it(i,0,n) {ll j; cin>>j; j%2 == 0 ? evensB.pb(j) : oddsB.pb(j);}

        ll smallEven, smallOdd, largeEven, largeOdd;
        if (evensA.size() < evensB.size()) {smallEven = evensA.size(), largeEven = evensB.size();}
        else {smallEven = evensB.size(), largeEven = evensA.size();}
        if (oddsA.size() < oddsB.size()) {smallOdd = oddsA.size(), largeOdd = oddsB.size();}
        else {smallOdd = oddsB.size(), largeOdd = oddsA.size();}

        it(i,0,smallOdd) ans += (oddsA[i] + oddsB[i]) / 2;
        it(i,0,smallEven) ans += (evensA[i] + evensB[i]) / 2;

        ll indOdd = smallOdd;
        ll indEven = smallEven;

        while (indOdd < largeOdd && indEven < largeEven) {
            ans += evensA.size() == smallEven ? (evensB[indEven] + oddsA[indOdd]) / 2 :
                (evensA[indEven] + oddsB[indOdd]) / 2;
            indOdd++; indEven++;
        }
        cout<<ans<<endl; 



    }
}