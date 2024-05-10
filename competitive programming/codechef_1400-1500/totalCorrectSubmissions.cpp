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
    //ifstream cin("totalCorrectSubmissions.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        map<string, int> probs;
        int n; cin>>n; 
        it(i,0,3) {
            it(j,0,n) {
                string s; int k; cin>>s>>k; 
                probs[s] += k;
            }
        }
        vi solved;
        for (auto& pair:probs) solved.pb(pair.ss);
        sort(all(solved));
        it(i,0,solved.size()) cout<<solved[i]<<" ";
        cout<<endl; 
    }
}