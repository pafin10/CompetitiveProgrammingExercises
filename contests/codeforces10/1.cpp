#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main(int argc, char const *argv[])
{
    //ifstream cin("1.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        int n, k; cin>>n>>k;
        if (k >= (n-1)) cout<<1<<endl; 
        else cout<<n<<endl; 
    }
	return 0;
}