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
    //ifstream cin("2.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int n,m; cin>>n>>m; 
        string a,b; cin>>a>>b;
        int i = 0, j = 0, cnt = 0;
        while (j<m) {
            char curr = a[i];
            if (b[j] == curr) {cnt++; i++; j++;}
            else j++;
        }
        cout<<cnt<<endl; 
    }
}