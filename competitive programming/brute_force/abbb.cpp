#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)
#define pb push_back


int main(int argc, char const *argv[]) {
    // ifstream cin("abbb.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t; 
    while(t--) {
        string s; cin>>s; 
        int cnt = 0, n = s.length();
        it(i, n) {
            (s[i] == 'B' && cnt > 0) ? cnt-- : cnt++;
        }
        cout<<cnt<<endl; 
    }

    return 0;
}
