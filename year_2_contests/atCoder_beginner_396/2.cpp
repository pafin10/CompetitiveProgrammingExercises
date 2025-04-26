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
#include <stack>


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
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t; 
    stack<int> st; 
    for (int i = 1; i <= 100; i++) st.push(0);
    
    while(t--) {
        int c; cin>>c;
        if (c == 1) {
            int j; cin>>j;
            st.push(j);
        }
        else {
            int out = st.top();
            st.pop();
            cout<<out<<endl; 
        }
    }
}