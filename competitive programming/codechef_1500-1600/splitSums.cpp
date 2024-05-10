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
#include <numeric>


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
    //ifstream cin("splitSums.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        ll n, m; cin>>n>>m;
        vll a, b;
        ll sumA = 0, sumB = 0; 
        ll totSum = n*(n+1) / 2; 
        sumB = (totSum - m)/2;

        sumA = totSum - sumB;
        (gcd(sumA, sumB) == 1 && abs(sumA-sumB) == m) ? cout<<"Yes"<<endl : cout<<"No"<<endl; 

    }
}