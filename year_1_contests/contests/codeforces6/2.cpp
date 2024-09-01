#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>
#include <utility>
#define endl "\n"
#define ll long long
#define all(x) (x).begin(), (x).end()

using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
    ifstream cin("2.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin>>n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) cin>>a[i].first;
        for (int i = 0; i < n; i++) cin>>a[i].second;

        sort(all(a));
        for (int i=0; i<n; i++) cout<<a[i].first<<" \n"[i+1==n];
		for (int i=0; i<n; i++) cout<<a[i].second<<" \n"[i+1==n];

    }
    return 0;
}