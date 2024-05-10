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
    //ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        int maxSum = 0, numOps = 2*n;        

        for (int i = 1; i <= n; i++) {
            maxSum += i* (2*i-1);
        }
        cout<<maxSum<<" "<<numOps<<endl; 
        for(int j = n; j>=1; j--) {
            it(k, 1, 3) {
                cout<<k<<" "<<j<<" ";
                it(i,1,n+1) cout<<i<<" ";
                cout<<endl; 
            }
        }
    }
}