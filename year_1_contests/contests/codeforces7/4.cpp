// CHECK SOLUTIONS!
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main(int argc, char const *argv[])
{
    //ifstream cin("4.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        int n; cin>>n;
        vector<int> a(n), p(n, -1);
        it(i, n) {
            cin>>a[i];
            if (i == 0 || a[i] != a[i-1]) p[i] = i-1;
            else p[i] = p[i-1];
        }
        int q; cin>>q; 
        while(q--) {
            int l, r; cin>>l>>r; 
            l -= 1; r -=1;
            if (p[r] >= l) cout<< p[r] + 1 << " " << r + 1 <<endl;
            else cout<<"-1 -1"<<endl;
        }
    }
        
	return 0;
}