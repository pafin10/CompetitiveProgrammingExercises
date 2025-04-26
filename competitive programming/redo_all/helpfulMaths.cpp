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
    // ifstream cin("helpfulMaths.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin>>s; 
    vector<int> a; 

    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) a.push_back(stoi(string() + s[i]));
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++) {
        cout<<a[i];
        if (i < a.size() - 1) cout<<"+";
    }
    cout<<endl; 
}