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
#include <cassert>


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

     //ifstream cin("mexGame1.txt");
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        vi occ(n+1,0);
        it(i, 0, n) {
            int j; cin>>j; 
            occ[j]++;
        }

        int cnt = 0, ans=-1;
        bool first = true; 

         it(i,0,n+1) {
            cnt += (occ[i] == 1);
            if (cnt==2 || occ[i] == 0) {
                ans=i;
                break;
            }
         }
        cout<<ans<<endl; 

    }
}