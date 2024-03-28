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
    // MY IDEA AND BASIC LOGIC WAS BASICALLY THE SAME, BUT IMPLEMENTED WORSE
    // ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        int n, q; cin>>n>>q; 
        vector<ll> c(n);
        vector<ll> minSum(n+1), runSum(n+1);
        it(i, n) {
            cin>>c[i];
            runSum[i+1] = (c[i] + runSum[i]);
            minSum[i+1] = minSum[i] + (c[i] == 1 ? 2 : 1);
        }

        it(i, q) {
            ll l, r; cin>>l>>r; 
            l--;
            ll curr = runSum[r]-runSum[l];
            ll mini = minSum[r]-minSum[l];
            string ans = "";

            if (curr >= mini && r-l >= 2) {
                ans = "YES";
            }
            else {
                ans = "NO"; 
            }
            cout<<ans<<endl;
        }
    }
	return 0;
}