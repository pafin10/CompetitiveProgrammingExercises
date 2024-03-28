#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main(int argc, char const *argv[])
{
     ifstream cin("k_DivSum.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        int n, k; cin>>n>>k;
        double l = ceil(double(n)/k);
        double maxEl = ceil(l*k/n);
        cout<<int(maxEl)<<endl;

    }
	return 0;
}