#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <array>
#include <deque>
#include <functional>


using namespace std;
#define NDEBUG
#define endl "\n"
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int)x.size()
//#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  


int32_t main() {
    // ifstream cin("aCharacteristic.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 
        
        if (k == 0) {
            if (n == 2) {
                cout<<"YES"<<endl; 
                cout<<1<<" "<<-1<<endl;
            }
            else cout<<"NO"<<endl; 
            continue;
        }

        int ones = -1;
        for (int i = 0; i <= n / 2; i++) {
            if (((i * (i - 1) / 2) + ((n - i - 1) * (n - i)) / 2) == k) {
                ones = i; 
                break;
            }
        }
        if (ones != -1) {
            cout<<"YES"<<endl; 
            for (int i = 0; i < n; i++) {
                if (i < ones) cout<<1<<" ";
                else cout<<-1<<" ";
            }
            cout<<endl;
        }
        else cout<<"NO"<<endl; 
        
    }
}