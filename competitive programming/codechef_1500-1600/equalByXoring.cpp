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
    //ifstream cin("equalByXoring.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        ll a,b,n; cin>>a>>b>>n;
        if (a==b) {cout<<0<<endl; continue;}
        ll x = a^b;
        if (x < n) {cout<<1<<endl; continue;}
        else {
            ll msBNum = 1;
            while (msBNum <= x) msBNum = (msBNum<<1);
            msBNum/=2;
            if (msBNum >= n) {cout<<-1<<endl; continue;}
            cout<<2<<endl; 
        }

    }
}