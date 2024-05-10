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

static vector<bool> sieve(int n);

static vector<bool> sieve(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = false; isPrime[1] = false; 
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false; 
            }
        } 
    } 
    return isPrime;
}
vector<bool> isPrime = sieve(1'000'000);

int main(int argc, char const *argv[]) {
    //ifstream cin("monsters.txt"); //DEBUG LATER
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int h; cin>>h;
        int p = 1, cnt = 0; 
        while (h > 0) {
            if (p==h) {cnt++; h=0; break;}
            if (isPrime[h]) {cnt++; h -= h; break;}
            h -= p; p *= 2; cnt++;
        }
        if (h==0) cout<<cnt<<endl; 
        else cout<<-1<<endl; 
    }
}