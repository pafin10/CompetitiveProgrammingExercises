#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_map>


using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define itb(i, start, n) for (int i = start; i >= n; --i)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
#define int long long
const int MAX_N = 100'005;

int32_t main() {
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k;
        int maxVal = 0;
        it(i,1,n+1) maxVal += abs(i-(n-i));

        if (k & 1 || k > maxVal) {cout<<"No"<<endl; continue;}
        k /= 2; 
        vi ans(n);
        iota(all(ans), 0);

        it(i,0,n) {
            if (i < n-1-i) {
                if (k == 0) break; 
                if (k <= (n-1-i)-i) {
                    it(j,i,n-i) {
                        if (ans[j] == j && k == j-i) {
                            swap(ans[j], ans[i]);
                            k -= j-i;
                            break; 
                        }
                    }
                }
                else {
                    swap(ans[i], ans[n-i-1]);
                    k -= abs((n-1-i)-i);
                }
            }
        }
        if (k) {cout<<"No"<<endl; continue;}
        cout<<"Yes"<<endl; 
        for (auto& a : ans) cout<<a+1<<" ";
        cout<<endl; 
        
    }
}