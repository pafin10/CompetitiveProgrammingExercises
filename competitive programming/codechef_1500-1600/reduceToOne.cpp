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
const ll MOD = 100'000'0007;

int main(int argc, char const *argv[]) {
    //ifstream cin("reduceToOne.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    vll a(1'000'001, -1);
    a[1] = 1;
    int solvedInd = 1;
    while(t--) {
        ll n; cin>>n; 
        if (a[n] != -1) {cout<<a[n]<<endl; continue;}
        else {
            it(i, solvedInd+1, n+1) {
                a[i] = ((a[i-1]%MOD) + (i%MOD) + (a[i-1]%MOD) * (i%MOD))%MOD;
            }
            solvedInd = n;
            cout<<a[n]<<endl;
        }
    }
}