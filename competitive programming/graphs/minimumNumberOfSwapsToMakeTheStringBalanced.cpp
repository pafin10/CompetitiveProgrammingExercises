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
#include <stack>
#include <unordered_map>


using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
//#define int long long
const int MAX_N = 100'005;

int minSwaps(string s) {
    int n = s.length(), ans = 0;
    stack<char> st; 

    for (int i = 0; i < n; i++) {
        if (s[i] == '[') st.push(s[i]);
        else {
            if (st.empty()) st.push(s[i]);
            else if (st.top() == ']') st.push(s[i]);
            else st.pop();
        }
    }
    
    while (!st.empty() && st.top() != ']') {
        st.pop();
        ans++;
        if (st.top() == ']') break;
        st.pop(); 
    }
    return ans; 
}
int32_t main() {
    ifstream cin("minimumNumberOfSwapsToMakeTheStringBalanced.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin>>s; 
    cout<<minSwaps(s)<<endl; 
}