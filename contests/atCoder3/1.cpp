#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#define endl "\n"
#define ll long long
#define it(i, n) for(int i = 0; i<n; i++)
using namespace std;

int main() {
    // ifstream cin("1.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin>>n>>k; 
    it (i, n) {
        int j; cin>>j; 
        if (j % k == 0)  cout<<(j/k)<<" ";
    }
    cout<<endl; 
	return 0;
}