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
    // ifstream cin("mrPerfectlyFine.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        int a = 10 * MAX_N ,b = 10 * MAX_N ,c = 10 * MAX_N; 

        for (int i = 0; i < n; i++) {
            int mi; cin>>mi;
            string books; cin>>books;
            if (books == "10") a = min(mi, a);
            else if (books == "01") b = min(mi, b);
            else if (books == "11") c = min(mi, c);
        }
        if ((a < 10 * MAX_N && b < 10 * MAX_N) || c < 10 * MAX_N) cout<<min(a + b, c)<<endl; 
        else cout<<-1<<endl;
    }
}