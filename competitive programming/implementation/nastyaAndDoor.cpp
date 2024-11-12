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


using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>


int main(int argc, char const *argv[]) {
     ifstream cin("nastyaAndDoor.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin>>t; 
    while(t--) {
        int n, k; cin>>n>>k; 
        vi a(n), peaks, starts(n-2);
        int cnt = 0;
        it(i,0,n) {
            cin>>a[i];
            if (i>1) {
                if (a[i] < a[i-1] && a[i-1] > a[i-2]) {
                    cnt++;
                    peaks.pb(i-1);
                    starts[i-2] = cnt;
                }
                else starts[i-2] = cnt;
            }
        }
        int ansPos = 0, parts = 0, max = 0;
        it (i, 0, n-k+1) {
            int diff = starts[i+k-3] - starts[i-1];
            if (i==0) diff = starts[i+k-3];
            if (diff > max) {
                max = diff;
                parts = max+1;
                ansPos = i+1;
            }
        }
        if (parts == 0 && ansPos == 0) {parts=1, ansPos=1;}
        cout<<parts<<" "<<ansPos<<endl; 
    }
    return 0;
}