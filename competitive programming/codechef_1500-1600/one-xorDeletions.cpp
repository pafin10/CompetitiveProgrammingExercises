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
    //ifstream cin ("one-xorDeletions.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    int maxPos = 0;
    while(t--) {
        int n; cin>>n;
        vi a(n+1, 0);
        it(i,0,n) {
            int j; cin>>j;
            a[j]++;
            if (a[j] > maxPos) maxPos = j; 
        }
        // count # of most occurences - check adjacent number with lsb set /unset
        int pairSum = 0;
        for (int i = 0; i < n; i+=2) {
            int tmp = a[i] + a[i+1];
            if (tmp > pairSum) pairSum = tmp; 
        } 
        // Always consider even and uneven cases when iterating in steps of 2!!
        if (n%2==0) {
            if (a[n] > pairSum) pairSum = a[n];
        }
        cout<<n-pairSum<<endl; 

        
    }
}