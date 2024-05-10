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
#include <numeric>

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
    ifstream cin("4.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int n,k, b, s; 
        cin>>n>>k>>b>>s;
        vll p(n),a(n);
        vector<bool> visitedS(n, false), visitedB(n, false);
        it(i,0,n) cin>>p[i];
        it(i,0,n) cin>>a[i];

        b--; s--;
        ll scoreS = a[s], scoreB = a[b];
        b = p[b]-1, s = p[s]-1;
        ll bCycle = 0, sCycle = 0;
        
        it(i,1,n) {
            scoreS += a[s];
            scoreB += a[b];
            if (!visitedB[p[b]-1]) {visitedB[p[b]-1] = true; b = p[b]-1; bCycle++;}
            if (!visitedS[p[s]-1]) {visitedS[p[s]-1] = true; s = p[s]-1; sCycle++;}
            else if (visitedB[p[b]-1] && visitedS[p[s]-1]) break; 
            if (bCycle == k || sCycle == k) break;
        }
        ll runScoreB = 0, runScoreS = 0;
        vll sCycleMax, bCycleMax;
        it(i,0,bCycle) {
            scoreB = max(scoreB, runScoreB + a[b]*(bCycle-i-1));
            bCycleMax.pb(max(runScoreB + a[b], runScoreB + p[b]-1));
            runScoreB += a[b]; b = p[b]-1;
        }
        
        it(i,0,sCycle) {
            scoreS = max(scoreS, runScoreS + a[s]*(sCycle-i-1));
            sCycleMax.pb(max(runScoreS + a[s], runScoreS + p[s]-1));
            runScoreS += a[s]; s = p[s]-1;
        }
        scoreB = scoreB * k/bCycle;
        scoreS = scoreS * k/sCycle;

        if (k%bCycle != 0) scoreB += bCycleMax[(k%bCycle)-1];
        if (k%sCycle != 0) scoreS += sCycleMax[(k%sCycle)-1];

        if (scoreB > scoreS) {cout<<"Bodya"<<endl; continue;}
        else if (scoreB < scoreS) {cout<<"Sasha"<<endl; continue;}
        else cout<<"Draw"<<endl; 
    }
}