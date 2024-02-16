#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>
//#include <bits.stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main(int argc, char const *argv[])
{
    fastio;
    int t; cin >> t;
    while(t--) {
        int n; cin>>n;
        vector<int> a(n);
        ll sm = 0, odd = 0, cnt = 0, ans = 0;
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }

        for (auto& i : a) {
            sm += i;
            odd += i&1;
            cnt++;
            if (cnt == 1) {cout<<sm<<endl; continue;}

            ans = odd / 3; 
            if (odd%3 == 1) ans++;
            cout<<sm-ans<<" ";
        }
        cout<<endl;
        
    }

    return 0;
}

