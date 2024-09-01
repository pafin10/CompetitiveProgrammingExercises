#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>
#include <string>

#define endl "\n"
#define ll long long
#define it(i, n) for(int i = 0; i<n; i++)
using namespace std;

int main() {
    // ifstream cin("3.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b; cin>>n>>a>>b; 
    string ans = "YES";
    vector<int> p(n);
    it(i,n) {
        cin>>p[i];
        if (i>0) {
            int diff = p[i] - p[i-1];
            if (diff%(a+b) >= a && diff%(a+b) < b) {ans ="NO"; break;}
        }
    }
    cout<<ans<<endl; 



	return 0;
}