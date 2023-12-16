#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <fstream>

using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{

    ifstream cin("1.txt");

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, k; 
        cin>>n>>k; 
        vector<int> a(n);
        int cnt = 0;
        for (int i = 0; i<n;i++) cin>>a[i];
        int res = 0;
        for (int i = 0; i < k; i++) {
            res |= a[i];
        }
        if (res%2!=0) cnt++;

        for (int j = k; j < n; j++) {
            res = res ^ a[j-k] | a[j];
            if (res%2!=0) cnt++;
        }
        cout<<cnt<<endl;
    }
	return 0;
}

