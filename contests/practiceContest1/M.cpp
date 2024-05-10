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
#define itb(i, start, n) for (int i = start; i >= n; --i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef map<int, vi> MapType;



// Custom comparator to sort map keys based on the size of associated vectors
struct CompareByVectorSize {
    bool operator()(const pair<int, vi>& a, const pair<int, vi>& b) const {
        return a.second.size() < b.second.size();
    }
};

int main(int argc, char const *argv[]) {
    //ifstream cin("M.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; //cin>>t; 
    t=1;
    while(t--) {
        int n; cin>>n;
        vi a(n);
        vector<vi> guards(n);     
        vi state(n, 0); // 1 = in set, -1 = eliminated, 0 = unchecked
        it(i,0,n) {
            cin>>a[i];
            guards[a[i]-1].pb(i);
        }
        sort(all(guards), [] (const vi& a, const vi& b) {
            return a.size() > b.size();
        });
     
        int guardedPlanet = a[guards[0][0]];
        int cnt = guards[0].size();

        for (auto el: guards[0]) state[el] = 1;
        state[guardedPlanet-1] = -1 ;
        
        it(i,0,n) {
            if (state[i]==0 && state[a[i]-1] != 1) {
                cnt++;
                state[i] = 1;
                state[a[i]-1] = -1;
            }
        }

        cout<<cnt<<endl; 
           
    }
}