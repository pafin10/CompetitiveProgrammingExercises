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
//#define int long long
const int MAX_N = 100'005;


// WORKS, BUT NOT TOO EFFICIENT 

bool isPalindrome(string s) {
    string t = s;
    reverse(s.begin(), s.end());
    return s == t;
}

string longestPalindrome(string s) {
    int n = s.size(); 
    if (n == 1) return s; 
    string cur = "", curCopy = "", longestP = string(1, s[0]);

    for (int i = 0; i < n - 1; i++) {
        cur = s[i];
        curCopy = cur; 
        string nextChar = string(1, s[i+1]), nnextChar = "_";
        if (i < n - 2) nnextChar = string(1, s[i+2]);

        if (isPalindrome(cur + nextChar + nnextChar)) {
            cur = (cur + nextChar + nnextChar);
            int j = i - 1, k = i + 3;

            while (j >= 0 && k < n && s[j] == s[k]) {
                cur = (string(1, s[j]) + cur + string(1, s[k]));
                j--, k++;
            }
            if (cur.size() > longestP.size()) {
                longestP = cur;
            }

        }
        cur = curCopy;
        if (isPalindrome(cur + nextChar)) {
            cur = (cur + nextChar);
            int j = i - 1, k = i + 2;

            while (j >= 0 && k < n && s[j] == s[k]) {
                cur = (string(1, s[j]) + cur + string(1, s[k]));
                j--, k++;
            }

            if (cur.size() > longestP.size()) {
                longestP = cur;
            }
        }  
        if (cur == longestP) {
            
        }
    }
    return longestP;
}

int32_t main() {
    ifstream cin("longestPalindromicSubstring.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin>>s; 
    cout<<longestPalindrome(s)<<endl; 
    
}


